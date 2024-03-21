#include "../include/grupo.h"

struct rep_grupo {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TPersona grupo[MAX_PERSONAS];
    int tope;
    /****** Fin de parte Parte 5.1 *****/
};


TGrupo crearTGrupo(){
    TGrupo grupo = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    grupo = new rep_grupo;
    grupo -> tope = 0; 
    /****** Fin de parte Parte 5.2 *****/
    return grupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo& grupo, TPersona persona){
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    int i = 0;
    if (grupo -> tope < MAX_PERSONAS){
        if (grupo -> tope == 0){
            grupo -> grupo[i] = persona; 
            grupo -> tope++;
        }else{
            while (i < grupo -> tope){
                if (compararTFechas (fechaNacimientoTPersona(persona),fechaNacimientoTPersona(grupo->grupo[i])) >= 0){
                    i++;
                }
            }          
            for (int j = grupo -> tope ; j>=i ;j--){
                grupo -> grupo [j] = grupo -> grupo[j-1];   
            }
            grupo -> grupo [i] = persona;
            grupo -> tope++;
        }
    }    

    

    /****** Fin de parte Parte 5.2 *****/
}

// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo){
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    for(int i=0; i <= grupo -> tope-1 ;i++){
        imprimirTPersona(grupo -> grupo [i]);
    }
    /****** Fin de parte Parte 5.2 *****/
}

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo& grupo){
   /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    for(int i=0; i<= grupo -> tope -1 ; i++){
        liberarTPersona(grupo -> grupo[i]);
    }
    delete grupo;
    grupo = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula){
    bool esta = false;
	/************ Parte 5.3 ************/
    /*Escriba el código a continuación */
    int j = 0;
    while ((j <= grupo -> tope -1 ) && !esta){
        esta = (cedula == cedulaTPersona(grupo -> grupo[j]));
        j++;
    }
    /****** Fin de parte Parte 5.3 *****/
	return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula){
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    if (estaEnGrupo(grupo, cedula)){
        int j = 0;
        while (j < grupo -> tope){
            if (cedula == cedulaTPersona(grupo -> grupo[j])){
                liberarTPersona(grupo -> grupo[j]);
                for (int i=j; i < grupo -> tope; i++){
                    grupo -> grupo[i] = grupo -> grupo[i+1];
                }grupo -> tope--;
            }j++;
        }
    }
    /****** Fin de parte Parte 5.4 *****/   
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha){
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    //Variables auxiliares que me ayudaran a recorrer el arreglo
    int j = 0;
    int i = grupo -> tope -1;
    //Contempla el caso de que exista un solo elemento en el arreglo
    if (grupo -> tope == 1){
        hay = (compararTFechas(fechaNacimientoTPersona(grupo -> grupo [0]), fecha) == 0);
    }
    while (j <= i){
        int mitad = (j+ i) / 2;
        if (compararTFechas(fechaNacimientoTPersona(grupo -> grupo [mitad]), fecha) == 0){
            hay = true;
            break;
        }else
            //Si la fecha ubicada en la mitad es mas grende que la fecha que nos proporciona la funcion, covierte el tope en mitad -1 porque mitad ya se comparo
            if(compararTFechas(fechaNacimientoTPersona(grupo -> grupo [mitad]), fecha) > 0){
                i = mitad - 1;
        }else{
            j = mitad + 1;
        }

    }

    /****** Fin de parte Parte 5.5 *****/ 
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha" 
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha){
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/ 
}
