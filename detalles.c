#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"detalles.h"

struct EstrucDetalle {
    int cantidad;
    float precioUnidad;
    char descripcion[30];
};

Detalle crearDetalle(int cantidad, float precio, char descrip[30]) {
    Detalle d=malloc(sizeof(struct EstrucDetalle));//reserva la cantidad, sizeof:esta cantidad, que cantidad, ()
    //struct estrucVehiculo v;
    ///igual
    d->cantidad=cantidad;
    d->precioUnidad=precio;
    strcpy(d->descripcion,descrip);
    ///

    return d;
}
void mostrarDetalle(Detalle d) {
    printf("-------------------------\n");
    printf("CANTIDAD: %d\n",d->cantidad);
    printf("PRECIO: $%.2f.-\n",d->precioUnidad);
    printf("DESCRIPCION: %s\n",d->descripcion);
}
void cargarDetalleVacio(Detalle d){
    d->cantidad=-1;
    d->precioUnidad=-1;
    strcpy(d->descripcion,"Vacio");
}

///GETTERS
int getCantidad(Detalle d) {
    return d->cantidad;
}
float getPrecio(Detalle d) {
    return d->precioUnidad;
}
char * getDescrip(Detalle d) {
    return d->descripcion;
}
void liberarMemoriaDetalle(Detalle d){
    free(d);
}
///SETTERS
void setCantidad(Detalle d,int nuevaCantidad){
    d->cantidad=nuevaCantidad;
}
void setPrecio(Detalle d,float nuevoPrecio){
    d->precioUnidad=nuevoPrecio;
}
void setDescrip(Detalle d,char nuevaDescrip[]){
    strcpy(d->descripcion,nuevaDescrip);
}
