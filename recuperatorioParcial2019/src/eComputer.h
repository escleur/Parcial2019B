#ifndef CACHORRO_H_INCLUDED
#define CACHORRO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[200];
    int precio;
    int idTipo;
    char oferta[200];
}EComputer;

EComputer* ec_new();
EComputer* ec_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr,char* ofertaStr);
void ec_delete(EComputer* this);

int ec_setId(EComputer* this,int id);
int ec_getId(EComputer* this,int* id);

int ec_setDescripcion(EComputer* this,char* nombre);
int ec_getDescripcion(EComputer* this,char* nombre);

int ec_setPrecio(EComputer* this,int dias);
int ec_getPrecio(EComputer* this,int* dias);

int ec_setIdTipo(EComputer* this,int raza);
int ec_getIdTipo(EComputer* this,int* raza);

int ec_setOferta(EComputer* this,char* reservado);
int ec_getOferta(EComputer* this,char* reservado);

int compararPorTipo(void* e1, void* e2);

#endif // employee_H_INCLUDED
