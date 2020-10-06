#include"FuncionesMain.h"

void caracterFinal()
{
    // Puntero se ubica en el final del archivo para agregar un caracter nulo que es necesario
    FILE *archPtr;
    archPtr = fopen("ejemplo.txt", "a");
    // Condicional para comprobar que el fichero se abrio correctamente
    if(archPtr == NULL)  {
        printf("Error! No se pudo abrir el archivo\n");
        exit(1);
    }
    fseek(archPtr, 2, SEEK_END);  // Se ubica en el final del fichero
    fprintf(archPtr, "\0");  // Agrega el caracter nulo al final
    fclose(archPtr);  // Cierra el fichero
}

vector<Palabra> creaVectorFrecuencias(ifstream &archivoRead)
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

    // Declaracion de un vector llamado "diccionario" que almacenara las palabras y su frecuencia
    vector<Palabra> diccionario;

    // El bucle recorrera todo el archivo
    while(!archivoRead.eof())  {
        // Lee las lineas del documento, los almacena en "textoStr", despues lo convierte a arreglo de caracteres y lo almacena en "textoArray"
        getline(archivoRead, textoStr);
        strcpy(textoArray, textoStr.c_str());
        linea.setCharArray(textoArray);

        auxPtrArray = linea.getCharArray();

        while((*auxPtrArray) != '\0')  {  // Cuando llega al caracter nulo (al final de la linea) se sale del bucle...
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
        
        //... por lo que falta de contar la ultima palabra

        /* Cuando se agrega un salto de linea en el documento de texto, entonces la linea tendra al final un caracter nulo
        por lo tanto es necesario eliminar ese espacio haciendo modificaciones en la llamada al metodo "setPalabra" */

        // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
        auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));

        /*
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
            auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));
        }
        else  {
            // Sino hay caracter nulo al final de la palabra, manda a llamar a la funcion con los mismos argumentos
            // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
            auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));
        }
        // Restaura las variables auxiliares
        contAux = 0;
        */

        // Bucle que recorrera todo el diccionario
        for(Palabra p : diccionario)  {
            // Condicional para saber si alguna palabra del "diccionario" es igual a la ultima palabra de la "linea"
            if(p.esIgual(auxPalabra))  {     // no son iguales por el caracter nulo
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

    return diccionario;
}

void imprimeFrecuencias(vector<Palabra>* dic)
{
    // Bucle que recorrera todo el diccionario e imprimira cada palabra y su frecuencia
    for(Palabra p : *(dic))  {
        cout << "Palabra: " << p.getPalabra() << " - Frecuencia: " << p.getFrecuencia() << endl;
    }
}

int sumaFrecuencias(vector<Palabra>* dic)
{
    // Declaracion de variable auxiliar para almacenar la suma de las frecuencias
    int sum = 0;

    // Bucle que recorrera todo el diccionario e imprimira cada palabra y su frecuencia
    for(Palabra p : *(dic))  {
        sum += p.getFrecuencia();
    }

    return sum;
}