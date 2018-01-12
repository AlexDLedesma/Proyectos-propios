#include <stdio.h>
#include <string.h>

void menu();
void escritura(char *archivo, char *cadena, FILE *fp);
void opcion1(char *archivo, char *cadena, FILE *fp);
void opcion2(char *archivo, char *cadena, FILE *fp);
void opcion3(char *archivo, char *cadena, FILE *fp);

int main(void){
	
	menu();
	
	system ("PAUSE");
	return 0;
}

void escritura(char *archivo, char *cadena, FILE *fp){
	char c='a';
	system ("Cls");
	puts ("\n\n            ================= EDITOR DE TEXTOS =================        ");
	puts ("\n 's' = salir del fichero  'n' = sobreescribir  'r' = Volver al comienzo del fichero\n");
	do{
		c='a';
		fflush(stdin);
		gets (cadena);
		if (c=='s') break;
		if (c=='n'){
			system ("cls");
			puts ("\n\n            ================= EDITOR DE TEXTOS =================        ");
			puts ("\n's' = salir   'n' = sobreescribir    'r' = Volver al comienzo del fichero\n");
			fp = fopen (archivo,"w+"); 
		}
		if (strlen(cadena)<301){
			fputs(cadena, fp);
			fputs ("\n",fp);
		} 
		if (strlen(cadena)<2) c = cadena[0]; 
		// if (c=='r') rewind(archivo);
	} while (c!='s');
	fclose(fp);
}

void menu(){
	int i = 0,bandera = 0;
	char cadena[300]={'\0'}; // Almacena cada linea que se escriba
	char archivo[13]={'\0'}; // Almacena nombre de archivo
	FILE *fp;
	

	do{
		
		system ("cls");
		puts ("\n\n              ================= EDITOR DE TEXTOS =================        ");
		puts ("\n 1. Nuevo archivo de texto.\n 2. Abrir archivo de texto existente para editar.\n 3. Abrir archivo de texto existente para lectura.\n 4. Salir del editor. \n");
	
	    scanf ("%d",&i);
	    
		switch(i){
			
			case 1: 
			    opcion1(archivo,cadena,fp);
			   	break;
				
			case 2:
			
				opcion2(archivo,cadena,fp);
				break;
				
			case 3:
				
				opcion3(archivo,cadena,fp);
				break;
				
			case 4:
				
				break;
		}
		
	} while (i!=4);
}

void opcion1(char *archivo, char *cadena, FILE *fp){
	char o = 'a';
	
	printf (" - Nombre del archivo: ");
	fflush(stdin);
	scanf("%s",archivo);
	fp = fopen (archivo,"r");
	
	if (fp != NULL){
		
		puts ("  ARCHIVO YA EXISTENTE! Desea sobreescribir? S/N");
		fflush(stdin);
		scanf ("%c",&o);
		toupper(o);
		if (o=='S') fp = fopen (archivo,"w+");
		if (o=='N') menu();
		
	}
	
	else fp = fopen (archivo,"w+");
	escritura (archivo, cadena, fp);
}

void opcion2(char *archivo, char *cadena, FILE *fp){
	char o = 'a';
	
	printf (" - Nombre de archivo: ");
	fflush(stdin);
	scanf("%s",archivo);
	fp = fopen (archivo,"r");
	
	if (fp == NULL){
		
		printf ("  ARCHIVO INEXISTENTE! Desea crearlo? S/N ");
		fflush(stdin);
		scanf ("%c",&o);					
		toupper(o);
		if (o=='S') fp = fopen (archivo,"w");
		if (o=='N') menu();
		
	}
	
	else{
		
		fp = fopen (archivo,"a");
		escritura(archivo,cadena,fp);	
		
	}		
}

void opcion3(char *archivo, char *cadena, FILE *fp){
	char c;
	printf (" - Nombre de archivo: ");
	
	fflush(stdin);
	scanf("%s",archivo);
	
	fp = fopen (archivo,"r");
	if (fp == NULL) printf ("  ARCHIVO INEXISTENTE!");	
	else {
 	/* Lee línea a línea el fichero */
 		while ( fgets(cadena, 300, fp) != NULL ){
 			printf("%s", cadena);		
 		}
	 }
}

