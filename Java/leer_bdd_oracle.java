import java.io.*;
import java.sql.*;//conecta a base de datos
class none{
 public static void main(String a[] ){
  String dbUrl="jdbc:odbc:bddpropia";// conexion via odbc
  String user="user";
  String password="pass";
  try{
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");// carga los driver de conexion
   Connection c=DriverManager.getConnection(dbUrl,user,password);// establece conexxion se llama c
   Statement s=c.createStatement();
   String cadenaSql="SELECT * FROM alumno";
   ResultSet r =s.executeQuery( cadenaSql);// el resultado del la consulta lo deja en r
   boolean existe=false;
  
   while(r.next()){
    existe=true;
    System.out.println("RUT : "+r.getString("rut")+ " --NOMBRE: "+r.getString("nombre")+ " --Apellido: "+r.getString("email"));// get obtiene los tipos de datos de la tabla
    }
  
   if (!existe)
    System.out.println("No se encontraron datos en la tabla");
   r.close();
   s.close();
   c.close();
  }catch (ClassNotFoundException ex){
   System.out.println("error:"+ex.getMessage());
  }catch(SQLException ex){
   System.out.println("error:"+ex.getMessage());
  }
 }
}
