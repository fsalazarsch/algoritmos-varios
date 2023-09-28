# include <fstream.h>

int main()
{
// char letra;
 ofstream archivo("letras.txt");
 for(char letra='A';letra <= 'Z';letra++)
 archivo<< letra;
 for(int x=0; x<10; x++)
 archivo<<x ;
 archivo.close();
 return 0;
}