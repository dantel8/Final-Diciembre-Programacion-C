#ifndef DETALLES_H_INCLUDED
#define DETALLES_H_INCLUDED

struct EstrucDetalle;

typedef struct EstrucDetalle * Detalle;///crear tipo de dato int, char, float, double, Detalle
///FUNCIONES PRIMITIVAS Y NO PRIMIRTIVAS
///CONSTRUCTOR
Detalle crearDetalle(int cantidad, float precio, char descrip[30]);
void mostrarDetalle(Detalle d);
void cargarDetalleVacio(Detalle d);
///DESTRUCTOR
void liberarMemoriaDetalle(Detalle d);

///GETTERS
int getCantidad(Detalle d);
float getPrecio(Detalle d);
char * getDescrip(Detalle d);
///SETTERS
void setCantidad(Detalle d,int nuevaCantidad);
void setPrecio(Detalle d,float nuevoPrecio);
void setDescrip(Detalle d,char nuevaDescrip[]);




#endif // DETALLES_H_INCLUDED
