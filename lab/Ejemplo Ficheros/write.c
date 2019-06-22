#include <stdio.h>

main() {
	//El fichero es un tipo de dato FILE *.
	FILE *fp;
	int valorEjemplo = 3;
	//fopen recibe el nombre del archivo a abrir y el modo de apertura.
	//Los modos de apertura son :
   		// r -> para modo de lectura.
   		// w -> para modo de escritura. Si el archivo no existe se crea. Si existe se sobre escribe.
   		// a -> para modo de agregación. Si el archivo no existe se crea. Si existe se escribe desde el
   		//		final del archivo.
   		//Existen los mismos modos con + (r+,w+,a+) que sirven para leer y escribir al mismo tiempo.
	fp = fopen("./test.txt", "w+");
	//fprintf funciona como printf, solo que recibe, además, el fichero donde escribe.
	fprintf(fp, "This is testing for fprintf...\n");
	fprintf(fp, "El valor de valorEjemplo es %i...\n",valorEjemplo);
	//metodo que permite escribir un string. Recibe el string y el fichero de salida.
	fputs("This is testing for fputs...\n", fp);
	//Una vez termino de trabajar, DEBO cerrar el fichero de salida.
	fclose(fp);
}