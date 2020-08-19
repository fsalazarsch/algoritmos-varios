package main 

import (
    "database/sql"
    "net/http"
    "encoding/json"
    "github.com/gorilla/mux"
    _ "github.com/go-sql-driver/mysql"
)

var url ="mdb-test.c6vunyturrl6.us-west-1.rds.amazonaws.com"

type Product struct{
	Id int
	name string
	url_image string
	price float32
	discount int
	category string

}


func dbConnection()( db *sql.DB){
	dbDriver := "mysql"
	dbUser := "bsale_test"
	dbPasswd := "bsale_test"
	dbName := "bsale_test"
	db, err:= sql.Open(dbDriver, dbUser+":"+dbPasswd+"@tcp("+url+")/"+dbName)
	if err != nil {
		panic(err.Error())
	}
	return db

}

func All(w http.ResponseWriter, req *http.Request){

	db := dbConnection()
	selDB, err := db.Query(" SELECT id, name, IF(url_image is null, '', url_image), price, discount, category FROM product") 
	if err != nil{
		panic(err.Error())
	}

	p := Product{}
	products := []Product{}

	for selDB.Next(){
		var Id, discount int
		var price float32
		var name, url_image, category string
		err = selDB.Scan(&Id, &name, &url_image, &price, &discount, &category)
		if err != nil{
			panic(err.Error())
		}
		p.Id = Id
		p.name = name
		p.url_image = url_image
		p.price = price
		p.discount = discount
		p.category = category
		
		products = append(products, p)

	}

	json.NewEncoder(w).Encode(products)
	defer db.Close()
	}
func One(w http.ResponseWriter, req *http.Request){

	db := dbConnection()

	params := mux.Vars(req)
	selDB, err := db.Query("SELECT * FROM product where id = ?", params["id"]) 
	if err != nil{
		panic(err.Error())
	}

	p := Product{}
	products := []Product{}

	for selDB.Next(){
		var Id, discount int
		var price float32
		var name, url_image, category string
		err = selDB.Scan(&Id, &name, &url_image, &price, &discount, &category, )
		if err != nil{
			panic(err.Error())
		}
		p.Id = Id
		p.name = name
		p.url_image = url_image
		p.price = price
		p.discount = discount
		p.category = category
		
		products = append(products, p)
	}

	json.NewEncoder(w).Encode(products)
	defer db.Close()
	}

func getBybeneficiomarca(w http.ResponseWriter, req *http.Request){

	db := dbConnection()
	var qry string
	params := mux.Vars(req)
	if ((params["filter"] == "name")  || (params["filter"] == "category")){
		qry = "SELECT * FROM product where "+params["filter"]+" ILIKE %%"+params["value"]+"%%"
	}

	if ((params["filter"] == "price") || (params["filter"] == "discount")){
		qry = "SELECT * FROM product where "+params["filter"]+" >= "+params["value"]
	}
		
	selDB, err := db.Query(qry)

	if err != nil{
		panic(err.Error())
	}

	p := Product{}
	products := []Product{}

	for selDB.Next(){
		var Id, discount int
		var price float32
		var name, url_image, category string
		err = selDB.Scan(&Id, &name, &url_image, &price, &discount, &category)
		if err != nil{
			panic(err.Error())
		}
		p.Id = Id
		p.name = name
		p.url_image = url_image
		p.price = price
		p.discount = discount
		p.category = category
		
		products = append(products, p)

	}

	json.NewEncoder(w).Encode(products)
	defer db.Close()
	}


func main(){
	router := mux.NewRouter()

	//log.Println("Conectado")
	router.HandleFunc("/products", All).Methods("GET")
	router.HandleFunc("/products/{id}", One).Methods("GET")
	router.HandleFunc("/products/{filter}/{value}", getBybeneficiomarca).Methods("GET")

	http.ListenAndServe(":8080", router)
}
