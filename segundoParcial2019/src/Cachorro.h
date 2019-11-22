#ifndef CACHORRO_H_INCLUDED
#define CACHORRO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int dias;
    char raza[128];
    char reservado[3];
    char genero[2];
}Cachorro;

Cachorro* ca_new();
Cachorro* ca_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char* generoStr);
void ca_delete(Cachorro* this);

int ca_setId(Cachorro* this,int id);
int ca_getId(Cachorro* this,int* id);

int ca_setNombre(Cachorro* this,char* nombre);
int ca_getNombre(Cachorro* this,char* nombre);

int ca_setDias(Cachorro* this,int dias);
int ca_getDias(Cachorro* this,int* dias);

int ca_setRaza(Cachorro* this,char* raza);
int ca_getRaza(Cachorro* this,char* raza);

int ca_setReservado(Cachorro* this,char* reservado);
int ca_getReservado(Cachorro* this,char* reservado);

int ca_setGenero(Cachorro* this,char* genero);
int ca_getGenero(Cachorro* this,char* genero);

int compararPorNombre(void* e1, void* e2);

#endif // employee_H_INCLUDED
