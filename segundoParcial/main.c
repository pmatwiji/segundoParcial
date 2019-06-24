#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"
int main()
{
    int option;
    int test;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            test = controller_loadEmpleados("datos.csv",listaEmpleados);
            if(test==TRUE)
            {
                printf("Empleados cargados con exito.\n");
            }
            else
            {
                printf("Error, no se pudo cargar los datos.\n");
                system("pause");
                exit(EXIT_FAILURE);
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("No hay datos cargados.\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }

            system("pause");
            system("cls");
            break;
        case 3:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("No hay datos cargados.\n");
            }
            else
            {
                ll_map(listaEmpleados,employee_calcularSueldo);
            }

            system("pause");
            system("cls");
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("No hay datos cargados.\n");
            }
            else
            {
                controller_ListEmployeeConSueldo(listaEmpleados);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            printf("Gracias por utilizar el sistema.\n");
            system("pause");
            system("cls");
            break;
//        case 5:
//            listaEmpleadosDos = ll_filter(listaEmpleados,employee_empleadosPlatudos);
//            test = controller_guardarSueldos("platudos.csv",listaEmpleadosDos);
//            if(test==TRUE)
//            {
//                printf("Archivo guardado con exito.\n");
//            }
//            else
//            {
//                printf("Error, no se pudo guardar los datos.\n");
//            }
//            system("pause");
//            system("cls");
//            break;
        }
    }
    while(option != 3);
    return 0;
}
