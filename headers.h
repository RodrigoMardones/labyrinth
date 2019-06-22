
int ROWS = 0;
int COLS = 0;
int llave = 0;
//===============================================
//                  RETORNO DE PISO
//===============================================
char **piso(char *texto){
    int a,b;
    char aux,**piso;
    FILE *f1;
    char buff[255];
    f1 = fopen(texto,"r");
    //rescato las dimensiones del piso
    fscanf(f1,"%d",&a);
    //salto de linea para siguiente lectura
    fgets(buff,255,(FILE*)f1);
    //salto de linea para siguiente lectura
    fscanf(f1,"%d",&b);
    fgets(buff,255,(FILE*)f1);
    piso = (char**)malloc(sizeof(char*)*a);
    for(int j=0;j<a;j++){
        piso[j] = (char*)malloc(sizeof(char)*b);
        fscanf(f1,"%s",piso[j]);
        fgets(buff,b,(FILE*)f1);
        printf("%s",piso[j]);
    }
    fclose(f1);
    return piso;
}
//==================================================================
//                          busqueda en profundidad
//==================================================================
int iniciarmovimiento(char **piso,int x,int y){
    //muralla
    if(piso[x][y] == 'M'){
        return 0;
    }
    //visitado
    if(piso[x][y] == 'V'){
        return 0;
    }
    //subida
    if(piso[x][y] == 'S'){
        printf("Sube 1!\n");
        return 1;
    }
    if(piso[x][y]=='L'){
        printf("encontrada llave !\n");
        llave = 1;
    }
    if(piso[x][y] == 'T'){
        if(llave == 1){
            printf("Tesoro encontrador !!");
            return 2;
        }
    }
    piso[x][y] = 'V';
    return iniciarmovimiento(piso,x,y+1) + iniciarmovimiento(piso,x+1,y) + iniciarmovimiento(piso,x,y-1) + iniciarmovimiento(piso,x-1,y);
}
