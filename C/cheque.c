/* Crea un "cheque rudimentario" en .html */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
void conv_miles(int, char *);
char *escribir_cheque();
 
char referencia[20];
 
int main(){
     
    unsigned int monto = 0;
         
    escribir_cheque(monto);
         
    system("cheque.html");
     
    getchar();
    getchar();
    return 0;
    }
 
void conv_miles(int monto, char *strmonto){
      
          
    unsigned int dec = 0;
    unsigned int uni = 0;
     
      char unids[21][10] = {"un", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve",
     "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", 
     "dieciocho", "diecinueve", "veinte", "veinti"};
    char decen[16][15] = {"mil", "millon", "millones", "treinta", "cuarenta", "cincuenta", 
    "sesenta", "setenta", "ochenta", "noventa", "cien", "ciento", "cientos", "quinientos", "sete", "nove"};
                  
if (monto < 1000){
         if(monto == 100){
         strcpy(strmonto, strcat(strmonto, decen[10]));
         }
         else if((monto > 100) &&(monto < 200)){
         strcpy(strmonto, strcat(strmonto, decen[11]));
         }
         else if((monto/100) == 5){
         strcpy(strmonto, strcat(strmonto, decen[13]));
         }
         else if((monto/100) == 9){
         strcpy(strmonto, strcat(strmonto, decen[12]));
         }
         else if((monto/100) == 7){
         strcpy(strmonto, strcat(strmonto, decen[14]));
         strcpy(strmonto, strcat(strmonto, decen[12]));
         }
         else if (monto < 100){
               
         }
         else{
         strcpy(strmonto, strcat(strmonto, unids[(monto/100)-1]));
         strcpy(strmonto, strcat(strmonto, decen[12]));
         }
              dec = ((monto%100)/10);
              uni = monto%10;
              if((dec > 2) && (dec < 10)){
              strcpy(strmonto, strcat(strmonto, decen[dec]));
                                
                         if(uni != 0){
                         strcpy(strmonto, strcat(strmonto, "y "));
                         strcpy(strmonto, strcat(strmonto, unids[uni-1]));
                         }
              }
              else if((monto%100) < 21){
              strcpy(strmonto, strcat(strmonto, unids[(monto%100)-1]));
              }
              else if( ((monto%100) > 20) && ((monto%100) < 30)){
                   strcpy(strmonto, strcat(strmonto, unids[20]));
                   if(uni != 0){
                         strcpy(strmonto, strcat(strmonto, unids[uni-1]));
                         }
                   }
                
               }}
 
char *escribir_cheque(int monto){
      
    char nombre_portador[40];
    int tipo_port = 0;    
    char cantidad[10];
    char div[3];
    char strmonto[100];
     
    printf("Escribe del receptor:\t");
    scanf("%s",&nombre_portador);
    printf("A orden de o al portador:\n1)A orden de\n2)Al portador\n");
    scanf("%d", &tipo_port);
     
    printf("Escribe el Monto:\t");
    scanf("%s",&referencia);
     
        monto = atoi(referencia);
    if(monto > 1000000000)
             strcpy(strmonto, "ERROR");
     
    if(monto == 1000000000)
             strcpy(strmonto, "mil millones ");
    else{
          
          
    unsigned int short i = 0;
    for(i=0; i < 9 - strlen(referencia) ; i++){
             cantidad[i] = '0';
            }
     
    strncat(cantidad, referencia,10);     
    monto = atoi(strncpy(div, cantidad, 3));
 
    conv_miles(monto, strmonto);
    if(monto != 0)
    strcpy(strmonto, strcat(strmonto, " millones "));
     
    div[0] = cantidad[3]; div[1] = cantidad[4];div[2] = cantidad[5];
    monto = atoi(div);
     conv_miles(monto, strmonto);
    if(monto != 0)
    strcpy(strmonto, strcat(strmonto, " mil "));
     
    div[0] = cantidad[6]; div[1] = cantidad[7];div[2] = cantidad[8];
    monto = atoi(div);
     conv_miles(monto, strmonto);
     printf("%s", strmonto);
     }
     
    char t_ref[30];
    time_t fecha;
    struct tm * fech;
    time (&fecha);
    fech = localtime(&fecha);
    strftime(t_ref,30,"%x", fech);
     
     FILE * arch;
     arch = fopen("cheque.html","w+");
      
     fprintf(arch, "<html><center><font face=\"tahoma\">");
     fprintf(arch, "<table bgcolor=\"#00cfff\" width=\"50%c\" border=1><tr><td>", 37);
     fprintf(arch, "</td></tr><tr><td>%s</td><td align=\"right\">$<u>%s.-</u></td></tr><tr>",t_ref, referencia);
     if(tipo_port == 2)
     fprintf(arch, "<td><strike> pagese <br>a orden de </strike></td>");
     else
     fprintf(arch, "<td>pagese <br>a orden de</td>");
     fprintf(arch, "<td>%s</td></tr><td></td><tr>", nombre_portador);
     fprintf(arch, "<td>La suma de: %s</td><td></td></tr><td align=\"right\"><U>Pesos Mil</U></td>", strmonto);
     if(tipo_port == 1)
     fprintf(arch, "<td align=\"right\"><strike> o al portador</strike></td></tr><tr><td></td>");
     else
     fprintf(arch, "<td align=\"right\"> o al portador</td></tr><tr><td></td>");
     fprintf(arch, "<td align=\"right\">(firma aqui)</td></tr></table></font></center></html>");
      
     
     fclose(arch);
     return referencia;
     //system("cheque.html");
