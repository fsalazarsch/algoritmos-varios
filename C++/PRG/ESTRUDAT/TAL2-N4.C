/* SUPONGASE QUE LA OFICINA CATASTRAL ESTA LLEVANDO A CABO UNA INVESTIGACION
   SOBRE LAS LICENCIAS QUE SETE ORGANISMO EXPIDE.CADA USUARIO DEBE LLENAR UN 
   CUESTIONARIO QUE TENGA LA SIGUIENTE FORMA:

   ASUNTO
   TIPO DE LICENCIA   1 = CORREDOR
		      2 = VENDEDOR
   EDAD               A¥O EN EDAD
   SEXO               1 MASCULINO
		      2 FEMENINO
		      
   DISE¥E UN ALGORITMO QUE CALCULE:
   A. PORCENTAJE DE VENDEDORES Y CORREDORES
   B. EDAD PROMEDIO
   C. PORCENTAJE DE HOMBRES Y MUJERES
   TENIENDO EN CUENTA QUE EL PROCESO DE TOMA DE DATOS DEBE FINALIZAR CUANDO
   SE DE IUN NUMERO 0 COMO TIPO DE LICENCIA */


   # include <stdio.h>
   int c,cor,ven,mas,fem,ed,sex,tl,corr,vend,sed,mas,fem,pc,pv,pe,pm,pf;
   main()
   
   {
    clrscr();
    while (tl!=0){
	  printf("DIGITE TIPO DE LICENCIA ");
	  scanf("%d",&tl);
	  printf("DIGITE A¥O EN EDAD ");
	  scanf("%d",&ed);
	  printf("DIGITE SEXO ");
	  scanf("%d",&sex);
	  c = c+1;
	  if (tl == 1)
	      corr = corr + 1;
	     else
	       if (tl == 2) 
		   vend = vend + 1;
		}
	   
	   sed = sed + 1;
	   if (sex == 1)
	       mas = mas + 1;
	     else
	       if (sex == 2)
		  fem = fem + 1;
		
	    pc = ((corr * 100)/c);
	    pv = ((vend * 100)/c);
	    pe = (sed/c);
	    pm = ((mas * 100)/c);
	    pf = ((fem * 100)/c);

	    printf("EL PROMEDIO DE CORREDORES ES: ");
	    scanf("%d",&pc);
	    printf("EL PROMEDIO DE VENDEDORES ES: ");
	    scanf("%d",&pv);
	    printf("EL PROMEDIO DE EDADES ES: ");
	    scanf("%d",&pe);
	    printf("EL PROMEDIO DE SEXO MASCULINO ES: " );
	    scanf("%d",&pm);
	    printf("EL PROMEDIO DE SEXO FEMENINO ES: " );
	    scanf("%d",&pf);
	    getche();
   
 }
