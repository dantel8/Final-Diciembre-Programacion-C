#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include "detalles.h"

struct EstrucFecha;
typedef struct EstrucFecha * Fecha;
struct EstrucFactura;
typedef struct EstrucFactura * Factura;

///FUNCIONES PRIMITIVAS Y NO PRIMITIVAS
Fecha crearFecha(int d, int m,int a);
void mostrarFecha(Fecha f);
Factura crearFactura(int dia,int mes, int anio, char empresa[30]);
void mostrarFactura(Factura f);

///PRE:busca en la factura los detalles que estan vacios
///POST:retorna la posicion de un detalle vacio
int busquedaPosVacia(Factura f);
int busquedaPorDescrip(Factura f,char d[30]);
void agregarDetalle(Factura f, Detalle d);
void eliminarDetalle(Factura f,char d[]);
void editarDetalle(Factura f,char d[]);
void calcularTotal(Factura f);

///GETTERS
char * getEmpresa(Factura f);
int getDia(Fecha d);
int getMes(Fecha d);
int getAnio(Fecha d);
///SETTERS
void setDia(Factura f, int diaNuevo);
void setMes(Factura f, int mesNuevo);
void setAnio(Factura f, int anioNuevo);

#endif // FACTURA_H_INCLUDED
