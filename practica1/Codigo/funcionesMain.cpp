/**
 * @file FuncionesMain.cpp
 * 
 * Implementacion de las funciones principales para usar con la biblioteca "FuncionesMain.h".
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 10/10/2020
 */ 

#include"FuncionesMain.h"

void caracterFinal(char archivo[20])
{
    // Puntero se ubica en el final del archivo para agregar un caracter nulo que es necesario
    FILE *archPtr;
    archPtr = fopen(archivo, "a");
    // Condicional para comprobar que el fichero se abrio correctamente
    if(archPtr == NULL)  {
        printf("Error! No se pudo abrir el archivo\n");
        exit(1);
    }
    fseek(archPtr, 2, SEEK_END);  // Se ubica en el final del fichero
    fprintf(archPtr, "\0");  // Agrega el caracter nulo al final
    fclose(archPtr);  // Cierra el fichero
}

void creaVectorFrecuencias(ifstream &archivoRead, vector<Palabra> &diccionario)
{
    // Declaracion e iniciacion de variables auxiliares
    int contAux = 0;  // Auxiliares para el bucle "for"
    bool flagAux = false;
    int auxInicio = 0;  // Indicara el inicio de la palabra en el arreglo
    int auxFinal = 0;  // Indicara el fin de la palabra en el arreglo
    Palabra auxPalabra;
    char* auxPtrArray;  // Auxiliar para bucle "while"

    // Declaracion de la variable que almacenara el texto del documento
    string textoStr;

    // Declaracion de arreglo que contendra las palabras
    char textoArray[2000];

    // Declaracion de objeto "linea"
    LineaTexto linea;

    // El bucle recorrera todo el archivo
    while(!archivoRead.eof())  {
        // Lee las lineas del documento, los almacena en "textoStr", despues lo convierte a arreglo de caracteres y lo almacena en "textoArray"
        getline(archivoRead, textoStr);
        strcpy(textoArray, textoStr.c_str());
        linea.setCharArray(textoArray);

        auxPtrArray = linea.getCharArray();

        while((*auxPtrArray) != '\0')  {  // Cuando llega al caracter nulo (al final de la linea) se sale del bucle (sigue linea 100)...
            // Condicion para que revisa si se ha encontrado un espacio
            if(auxPtrArray[0] == ' ')  {
                // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
                auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));  // Resta 1 por el espacio

                /* Para entender esta parte del codigo: Solo existen dos estados de las palabras, que ya esten agregadas al "diccionario"
                o que no esten agregadas.
                En caso de que ya esten agregadas al "diccionario", entonces establece su frecuencia en 1, en caso contrario,
                incrementara su frecuencia */

                // Si el diccionario esta vacio, entonces agrega el primer elemento y establece su frecuencia en 1
                if(diccionario.size() == 0)  {
                    diccionario.push_back(auxPalabra);
                    diccionario[contAux].setFrecuencia(1);
                }
                else  {
                    // Bucle que recorrera todo el diccionario
                    for(Palabra p : diccionario)  {
                        // Condicional para saber si alguna palabra del "diccionario" es igual a la palabra en la que vamos en la "linea"
                        if(p.esIgual(auxPalabra))  {
                            flagAux = true;  // Cambia el valor del "flag" para no continuar con la siguiente condicional
                            diccionario[contAux].incrementaFrecuencia();  // Aumenta su frecuencia
                            break;  // Sale del bucle
                        }
                        // La ultilidad de esta variable es ir incrementando el valor del contador para irnos posicionando en cada indice del "diccionario"
                        contAux++;
                    }
                    // Si la "Palabra" no coincide con ninguna del "diccionario", entonces la agrega y establece su frecuencia en 1
                    if(!flagAux)  {
                        diccionario.push_back(auxPalabra);
                        diccionario[contAux].setFrecuencia(1);
                    }
                }
                // Restaura variables auxiliares
                flagAux = false;
                contAux = 0;

                /* Si las palabras estan separadas por un unico espacio, enconces la variable auxiliar que indica el inicio de la palabra se
                posicionara al principio de la siguiente palabra, saltandose el espacio y ubicandose en la primera letra de la siguiente palabra*/
                auxInicio = auxFinal + 1;
                // Se pisiciona "auxFinal" en la misma posicion que "auxInicio" para seguir el conteo
                auxFinal = auxInicio;
            }

            else  {
                auxFinal++;
            }
            auxPtrArray++;
        }
        
        //(continuacion linea 49)... por lo que falta de contar la ultima palabra

        // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
        auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));

        /*
        // Codigo en caso de que haya un salto de linea antes del caracter nulo

        //auxPtrArray = linea.getCharArray();
        contAux = auxInicio;  // Variable que se usara en el bucle "while"

        // Bucle que recorrera la ultima palabra
        while(contAux <= auxFinal)  {
            // Condicional para saber si al final de la palabra esta el caracter nulo
            if(*(auxPtrArray + contAux) == '\0')  {
                flagAux = true;  // Significa que se encontro un caracter nulo al final de la palabra
            }
            contAux++;
        }
        if(flagAux)  {
            // Como hay un carater nulo al final de la palabra, entonces se le debe restar 2 a "auxFinal"
            // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
            auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 2) - auxInicio)));
        }
        else  {
            auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));
        }
        // Restaura las variables auxiliares
        contAux = 0;
        */

        // Bucle que recorrera todo el diccionario
        for(Palabra p : diccionario)  {
            // Condicional para saber si alguna palabra del "diccionario" es igual a la ultima palabra de la "linea"
            if(p.esIgual(auxPalabra))  {
                flagAux = true;  // Cambia el valor del "flag" para no continuar con la siguiente condicional
                diccionario[contAux].incrementaFrecuencia();  // Aumenta su frecuencia
                break;  // Sale del bucle
            }
            contAux++;
        }
        // Si la "Palabra" no coincide con ninguna del "diccionario", entonces la agrega y establece su frecuencia en 1
        if(!flagAux)  {
            diccionario.push_back(auxPalabra);
            diccionario[contAux].setFrecuencia(1);
        }

        // Restaura las variables auxiliares
        auxInicio = 0;
        auxFinal = 0;
        contAux = 0;
        flagAux = false;
    }
}

void imprimeFrecuencias(vector<Palabra>* dic)
{
    // Bucle que recorrera todo el diccionario e imprimira cada palabra y su frecuencia
    for(Palabra p : *(dic))  {
        cout << left << "Palabra: " << setw(30) << p.getPalabra() << "Frecuencia: " << setw(30) << p.getFrecuencia() << endl;
    }
}

int sumaFrecuencias(vector<Palabra>* dic)
{
    // Declaracion de variable auxiliar para almacenar la suma de las frecuencias
    int sum = 0;

    // Bucle que recorrera todo el diccionario y sumara la frecuencia de cada palabra
    for(Palabra p : *(dic))  {
        sum += p.getFrecuencia();
    }

    // Regresa el total de palabras que hay en el "diccionario"
    return sum;
}

void empiezaTabla(ofstream &archivoWrite)
{
    escribeLinea(archivoWrite);
    archivoWrite << left << "|" << setw(20) << "PALABRA"  << setw(21) << "|FRECUENCIA" << "|\n";
    escribeLinea(archivoWrite);
}

void escribeLinea(ofstream &archivoWrite)
{
    archivoWrite << "+--------------------+--------------------+\n";
}

void escribeMayor(vector<Palabra> &dic, ofstream &archivoWrite)
{
    // Declaracion de variables auxiliares
    int auxRecorrido = 0;
    int auxIndice = 0;
    int auxMayor = 0;

    // Bucle que recorrera todo el "diccionario"
    for(Palabra p : dic)  {
        // Condicional para saber si la frecuencia de la palabra en la que vamos en el bucle es mayor a la frecuencia mayor visto hasta el momento
        if(p.getFrecuencia() > auxMayor)  {
            auxMayor = p.getFrecuencia();  // El valor mayor visto hasta el momento
            auxIndice = auxRecorrido;  // El indice de la palabra con la frecuencia mayor vista hasta el momento
        }

        // Para irnos ubicando en cada indice del "diccionario"
        auxRecorrido++;
    }

    // Escribira en el documento de texto la "Palabra" con mayor frecuencia vista hasta el momento
    archivoWrite << left << "|" << setw(20) << dic[auxIndice].getPalabra() << "|" << setw(20) << dic[auxIndice].getFrecuencia() << "|\n";

    // Elimina el elemento que se agrego al documento de texto
    dic.erase(dic.begin() + auxIndice);
}