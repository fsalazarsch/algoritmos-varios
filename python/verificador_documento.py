import requests,urllib
from bs4 import BeautifulSoup

url2 = "http://www.registrocivil.cl/principal/servicios-en-linea/consulta-vigencia-documento-1"
url="https://portal.sidiv.registrocivil.cl/usuarios-portal/pages/DocumentRequestStatus.xhtml"
headers={"Content-Type":"application/x-www-form-urlencoded",
"User-Agent":"Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.120 Safari/537.36"}

Run="18629465-3"
docType="CEDULA" #{CEDULA,CEDULA_EXT,PASAPORTE_PG,PASAPORTE_DIPLOMATICO,PASAPORTE_OFICIAL}
docNumber="102203213" #https://www.srcei.cl/PortalSIDIV/ayuda_documento.html

#cert=ssl.get_server_certificate(('portal.sidiv.registrocivil.cl',443),ssl_version=3)


cookie = {'JSESSIONID': 'EEE3A803DB6E99DB0A64CBDD0499383D.tomcat4'}
s=requests.Session()
s.headers.update(headers)
r=s.get(url, cookies=cookie,  verify=False)
soup=BeautifulSoup(r.content,"html.parser")

viewState=soup.find(id="javax.faces.ViewState")['value']
#viewState = "-1258754936833368300:8792190599638879979"
data={"form":"form", "form:run":Run, "form:selectDocType":docType, 
"form:docNumber":docNumber,"form:buttonHidden":"","javax.faces.ViewState":viewState}

r=s.post(url, data=data, cookies=cookie)
#ahora parsemaos el contenido

soup=BeautifulSoup(r.content,"html.parser")
tabla =soup.find("table", {"id": "tableResult"})
vigencia = tabla.find("td" , class_= "setWidthOfSecondColumn")
if vigencia.get_text() == "Vigente":
	print(True)
else:
	print(False)
#print(r.content)
