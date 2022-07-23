#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregar(char producto[][25],int *precio, int tam);
void eliminar(char producto[][25], int *precio, int tam);
void modificar(char producto[][25], int *precio, int tam);
void buscar(char producto[][25], int *precio, int tam);
void mostrar(char producto[][25], int *precio, int tam);

void Comprador(int *carrito, int *canti, int l);
void carrito(char producto[][25], int *precio, int *carrito, int *canti, int l);
void pago(char producto[][25], int *precio, int *carrito, int *canti, int l);

int main(){

int bucle = 1, n = 0, contra = 0, tam=0, op=0, np, i, z;

char produ[100][25];
int pre[100];
int carr[100];
int can[100];
int l[100];

do{

    system("cls");
    printf("-----Punto de venta-----\n");
    printf("Escoga una opcion\n");
    printf(" 1 - Gerente\n");
    printf(" 2 - Comprador\n");
    printf("\n");
    printf(" 0 - Salir\n");
    printf("------------------------\n");
    scanf("%i",&n);

    switch (n){

    case 1:
        system("cls");
        printf("Ingrese la contraseña numerica: ");
        scanf("%i",&contra);

        if(contra == 12345){
            system("cls");
            do{
                system("cls");
                printf("-----Menu de Gerente-----\n");
                printf(" 1 - Agregar\n");
                printf(" 2 - Eliminar\n");
                printf(" 3 - Modificar\n");
                printf(" 4 - Buscar\n");
                printf(" 5 - Mostrar productos\n");
                printf("\n");
                printf(" 0 - Salir\n");
                printf("-------------------------\n");
                scanf("%i",&op);

                switch(op){

                case 1:
                    system("cls");
                    printf("Cuantos valores desea agregar? ");
                    scanf("%i",&np);
                    agregar(produ,pre,np);
                break;
                case 2:
                    eliminar(produ,pre,np);
                break;
                case 3:
                    modificar(produ,pre,np);
                break;
                case 4:
                    buscar(produ,pre,np);
                break;
                case 5:
                    mostrar(produ,pre,np);
                break;
                case 0:
                    op = 0;
                break;

                }
            }while(op!=0);
        }
        else{
            system("cls");
            printf("Contraseña Incorrecta!!!");
        }
    break;
    case 2:
        system("cls");
        do{
            system("cls");
            printf("-----Menu de Comprador-----\n");
            printf(" 1 - Mostrar productos\n");
            printf(" 2 - Buscar productos\n");
            printf(" 3 - Ver Carrito\n");
            printf(" 4 - Pagar productos\n");
            printf("\n");
            printf(" 0 - Salir\n");
            printf("---------------------------\n");
            scanf("%i",&op);

                switch(op){
                    case 1:
                        mostrar(produ,pre,np);
                        printf("Cuantos productos desea agregar? ");
                        scanf("%i",&z);
                        Comprador(carr,can,z);
                    break;
                    case 2:
                        buscar(produ,pre,np);
                    break;
                    case 3:
                        carrito(produ,pre,carr,can,z);
                    break;
                    case 4:
                        pago(produ,pre,carr,can,z);
                    break;
                    case 0:
                        op = 0;
                    break;
                }
        }while(op!=0);
    break;
    case 0:
        bucle = 0;
    break;

    }

}while(bucle != 0);

}

void agregar(char producto[][25], int *precio, int tam){

int i;
char a;

system("cls");
for(i=1;i<=tam;i++){
    printf("Nombre del producto %i: ",i);
    scanf("%s",&producto[i]);
    printf("Precio del producto %i: $",i);
    scanf("%i",&precio[i]);
    }
}

void eliminar(char producto[][25], int *precio, int tam){

int nc=0,i;

system("cls");
for(i=1;i<=tam;i++){
    printf("%i° - ",i);
    for(int j=0;j<=strlen(producto[i]);j++){
        printf("%c ",producto[i][j]);
        }
    printf("\t");
    printf("Precio del producto: $ %i\n",precio[i]);
    }
printf("\n");
printf("Que producto desea eliminar (numero)? ");
scanf("%i",&nc);
for(i=nc;i<=tam;i++){
    for(int j=0;j<strlen(producto[i]);j++){
        producto[i][j]=producto[i+1][j];
        precio[i]=precio[i+1];
        if(i==tam){
            producto[i][j]=0;
            precio[i]=0;
            }
        }
    }
}

void modificar(char producto[][25], int *precio, int tam){

int nc=0,i;

system("cls");
for(i=1;i<=tam;i++){
    printf("%i° - ",i);
    for(int j=0;j<=strlen(producto[i]);j++){
        printf("%c ",producto[i][j]);
        }
    printf("\t");
    printf("Precio del producto: $ %i\n",precio[i]);
    }
printf("\nQue producto desea modificar (numero)? ");
scanf("%i",&nc);
printf("Nombre del producto modificado: ");
scanf("%s",&producto[nc]);
printf("Precio del producto modificado: $",i);
scanf("%i",&precio[nc]);

}

void buscar(char producto[][25], int *precio, int tam){

int np=0,i;
char bus[25],m;

system("cls");
printf("Ingrese el nombre del producto: ");
scanf("%s",&bus);
int len2=strlen(bus);
for(i=1;i<=tam;i++){
    int len1=strlen(producto[i]);
    m=bus[0];
    for(int j=0;j<=strlen(producto[i]);j++){
        if(producto[i][j]==m){
            if(strncmp(&producto[i][j],bus,len2)==0){
                printf("\nSe encontro en la posicion: \n");
                printf("%i - ",i);
                for(int x=0;x<=strlen(producto[i]);x++){
                    printf("%c ",producto[i][x]);
                    }
                printf("$%i\n\n",precio[i]);
                }
            }
        }
    }
system("pause");
}

void mostrar(char producto[][25], int *precio, int tam){

int i;

system("cls");
for(i=1;i<=tam;i++){
    printf("%i° - ",i);
    printf("Nombre del producto: ");
    for(int j=0;j<=strlen(producto[i]);j++){
        printf("%c ",producto[i][j]);
        }
    printf("\t");
    printf("Precio del producto: $ %i\n",precio[i]);
    }
printf("\n");
system("pause");
}

void Comprador(int *carrito, int *canti, int l){

int i;

for(i=1;i<=l;i++){
    printf("\n\nNumero del producto %i: ",i);
    scanf("%s",&carrito[i]);
    printf("Cantidad del producto %i: ",i);
    scanf("%i",&canti[i]);
    }
}

void carrito(char producto[][25], int *precio, int *carrito, int *canti, int l){

int i;

system("cls");
printf("-----Carrito-----\n\n");
for(i=1;i<=l;i++){
    printf("%i° - ",i);
    printf("Nombre del producto: ");
    for(int j=0;j<=strlen(producto[i]);j++){
        printf("%c ",producto[i][j]);
        }
    printf("\t");
    printf("Precio del producto: $ %i\n",precio[i]);
    printf("Cantidad de producto %i= %i\n",i,canti[i]);
    printf("\n\n");
    }
printf("-----------------\n");

system("pause");
}

void pago(char producto[][25], int *precio, int *carrito, int *canti, int l){

int i,multi=0,paga=0;

system("cls");
printf("-------PAGO-------\n\n");
for(i=1;i<=l;i++){
    printf("%i° - ",i);
    printf("Nombre del producto: ");
    for(int j=0;j<=strlen(producto[i]);j++){
        printf("%c ",producto[i][j]);
        }
    printf("\t");
    printf("Precio del producto: $ %i\n",precio[i]);
    printf("Cantidad de producto %i= %i\n",i,canti[i]);
    multi=canti[i]*precio[i];
    printf("Total = %i\n\n",multi);
    paga=paga+multi;
    }
printf("------------------\n");
printf("\nTOTAL A PAGAR: %i\n",paga);

system("pause");
}
