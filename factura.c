#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"factura.h"


struct EstrucFecha {
    int dia;
    int mes;
    int anio;
};

struct EstrucFactura {
    char empresa[30];
    float total;
    Fecha date;
    Detalle detail[5];
};
Fecha crearFecha(int d, int m, int a) {
    Fecha f=malloc(sizeof(struct EstrucFecha));

    f->dia=d;
    f->mes=m;
    f->anio=a;

    return f;
}
void mostrarFecha(Fecha f) {
    printf("FECHA: %d/%d/%d\n",f->dia,f->mes,f->anio);
}

Factura crearFactura(int dia, int mes, int anio, char empresa[30]) {
    Factura f=malloc(sizeof(struct EstrucFactura));

    f->date=crearFecha(dia,mes,anio);
    strcpy(f->empresa,empresa);
    for(int i=0; i<5; i++) {
        f->detail[i]=crearDetalle(-1,-1,"Vacio");

    }
    f->total=-1;

    return f;
}
void mostrarFactura(Factura f) {
    printf("EMPRESA: %s\n",f->empresa);
    mostrarFecha(f->date);
    for(int i=0; i<5; i++){
        if(strcmp(getDescrip(f->detail[i]),"Vacio")!=0) {
            mostrarDetalle(f->detail[i]);
        }
    }
    printf("-------------------------\n");
    printf("TOTAL= $%.2f.-\n",f->total);
}

int busquedaPosVacia(Factura f) {
    int pos=-1;

    for(int i=0; i<5; i++) {
        if(strcmp(getDescrip(f->detail[i]),"Vacio")==0) {
            pos=i;
            i=5;
        }
    }
    return pos;
}

void agregarDetalle(Factura f, Detalle d) {
    int pos=busquedaPosVacia(f);
    if (pos!=-1) {
        f->detail[pos]=d;
    }
}
int busquedaPorDescrip(Factura f,char d[30]){
    int pos=-1;
    for(int i=0;i<5;i++){
        if(strcmp(getDescrip(f->detail[i]),d)==0){
            pos=i;
        }
    }
    return printf("Pos: %d\n",pos);
}

void eliminarDetalle(Factura f,char d[]){
    for(int i=0; i<5; i++){
        if(strcmp(getDescrip(f->detail[i]),d)==0){
            cargarDetalleVacio(f->detail[i]);
        }
    }
}
void editarDetalle(Factura f,char d[]){
    int pos=busquedaPorDescrip(f,d);
    char nuevaDescrip[30];
    int nuevaCantidad;
    float nuevoValorUnidad;

    printf("ingrese una nueva descripcion\n");
    fflush(stdin);
    gets(nuevaDescrip);
    setDescrip(f->detail[pos],nuevaDescrip);

    printf("ingrese una nueva cantidad\n");
    scanf("%d",&nuevaCantidad);
    setCantidad(f->detail[pos],nuevaCantidad);

    printf("ingrese un nuevo precio\n");
    scanf("%f",&nuevoValorUnidad);
    setPrecio(f->detail[pos],nuevoValorUnidad);
}

void calcularTotal(Factura f) {
    int suma=0;

    for(int i=0; i<5; i++) {
        //que no este vacio
        if(strcmp(getDescrip(f->detail[i]),"Vacio")!=0) {
            suma=suma+(getCantidad(f->detail[i])*getPrecio(f->detail[i]));
        }
    }
    f->total=suma;
}

///GETTERS
int getDia(Fecha d) {
    return d->dia;
}
int getMes(Fecha d) {
    return d->mes;
}
int getAnio(Fecha d) {
    return d->anio;
}
char * getEmpresa(Factura f) {
    return f->empresa;
}
///SETTERS
void setDia(Factura f, int diaNuevo) {
    f->date->dia=diaNuevo;
}
void setMes(Factura f, int mesNuevo) {
    f->date->mes=mesNuevo;
}
void setAnio(Factura f, int anioNuevo) {
    f->date->anio=anioNuevo;
}
