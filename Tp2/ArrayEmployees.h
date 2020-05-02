#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;



void PrintEmployee(Employee lista);
int PrintEmployees(Employee lista[], int tam);



int InitEmployees (Employee lista[],int tam);
int BuscarLibre(Employee lista[],int tam);


//int AddEmployee(Employee lista[],int tam,int indiceLibre);
int addEmployee(Employee lista[],int tam,int idAnterior,char name[],char lastName[],float salary,int sector);

void ValidarCadena (char str[], char error[]);
int CargarEmpleado(Employee lista[],int tam,int idAnterior,char msj[],char error[]);

int GenerarId(Employee lista[],int tam, int idAnterior);
int FindEmployee(Employee lista[],int tam, int id);
int RemoveEmployee(Employee lista[],int tam, int id);


#endif // ARRAYEMPLOYEES_H_INCLUDED
