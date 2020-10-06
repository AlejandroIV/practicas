#include<iostream>
#include<vector>
#include"LineaTexto.h"
#include"Palabra.h"

using namespace std;

int main()
{
    // Declaracion e iniciacion de variables auxiliares
    int contAux = 0;
    bool flagAux = false;
    int auxInicio = 0;  // Indicara el inicio de la palabra en el arreglo
    int auxFinal = 0;  // Indicara el fin de la palabra en el arreglo
    Palabra auxPalabra;

    // Iniciacion de arreglo con 4 palabras
    char texto[] = {"Estas son cuatro palabras"};

    // Instanciacion de objeto "linea"
    LineaTexto linea(texto);
    
    // Auxiliar para bucle "while"
    char* auxPtrArray = linea.getCharArray();

    // Declaracion de un vector llamado "diccionario" que almacenara las palabras y su frecuencia
    vector<Palabra> diccionario;

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
    // Manda a llamar a la funcion para convertir el arreglo de caracteres a string
    auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));

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

    // Bucle que recorrera todo el diccionario e imprimira cada palabra y su frecuencia
    for(Palabra p : diccionario)  {
        cout << "Palabra: " << p.getPalabra() << " Frecuencia: " << p.getFrecuencia() << endl;
    }

    return 0;
}