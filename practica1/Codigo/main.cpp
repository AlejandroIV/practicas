#include<iostream>
#include<vector>
#include"LineaTexto.h"
#include"Palabra.h"

using namespace std;

int main()
{
    // Iniciacion de arreglo con 4 palabras
    char arreglo[] = {"1 2 2 3 3 3 4 4 4 4 5 5 5 5 5"};
    LineaTexto linea(arreglo);
    // Declaracion de variables auxiliares
    int auxInicio = 0;  // Indicara el inicio de la palabra en el arreglo
    int auxFinal = 0;  // Indicara el fin de la palabra en el arreglo
    Palabra auxPalabra;
    // Auxiliar para el ciclo "while"
    char* auxPtrArray = linea.getCharArray();
    // Auxiliares para el ciclo for
    int contAux = 0;  
    bool flagAux = false;
    // Declaracion de un vector llamado "diccionario" que contendra las palabras y su frecuencia
    vector<Palabra> diccionario;

    while((*auxPtrArray) != '\0')  {  // Cuando llega al caracter nulo (final de la palabra se sale)...
        // Condicion para que revisa si se ha encontrado un espacio
        if(auxPtrArray[0] == ' ')  {
            // Manda a llamar a la funcion para convertir los caracteres a una cadena de caracteres
            auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));  // Resta por el espacio

            /* Para entender esta parte del codigo: Solo existen dos estados de las palabras, que ya esten agregadas al "diccionario"
            o que no esten agregadas, en cualquier caso se incrementara alguna frecuencia en 1 */

            // Si el diccionario esta vacio, entonces agrega el primer elemento y establece su frecuencia en 1
            if(diccionario.size() == 0)  {
                diccionario.push_back(auxPalabra);
                diccionario[contAux].setFrecuencia(1);
            }
            else  {
                // Bucle para buscar si la "Palabra" es igual a alguna del "diccionario", si no para agregarla
                for(Palabra p : diccionario)  {
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

    //... por lo que falta de contar la palabra del final
    auxPalabra.setPalabra(auxPalabra.charArrayToString(linea.getCharArray(auxInicio), ((auxFinal - 1) - auxInicio)));
    // Bucle para buscar si la "Palabra" es igual a alguna del "diccionario", si no para agregarla
    for(Palabra p : diccionario)  {
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