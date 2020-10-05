#include<vector>
#include<string>
#include<iostream>

using namespace std;

string convertToString(char* a, int size);

int main()
{
    // Iniciacion de arreglo con 4 palabras
    char palabras[] = {"Estas son cuatro palabras"};
    // Declaracion de variables auxiliares
    int auxInicio = 0;  // Indicara el inicio de la palabra en el arreglo
    int auxFinal = 0;  // Indicara el fin de la palabra en el arreglo
    vector<string> palabra;

    for(char letra : palabras)  {
        // Condicion para que revisa si se ha encontrado un espacio
        if(letra == ' ' || letra == '\0')  {
            // Manda a llamar a la funcion para convertir los caracteres a una cadena de caracteres
            palabra.push_back(convertToString(&palabras[auxInicio], ((auxFinal - 1) - auxInicio)));  // Se resta 1 para no contar el espacio

            /* Si las palabras estan separadas por un unico espacio, enconces la variable auxiliar que indica el inicio de la palabra se
            posicionara al principio de la siguiente palabra, saltandose el espacio y ubicandose en la primera letra de la siguiente palabra*/
            auxInicio = auxFinal + 1;
            // Se pisiciona "auxFinal" en la misma posicion que "auxInicio" para seguir el conteo
            auxFinal = auxInicio;
        }

        else  {
            auxFinal++;
        }
    }

    for(string p : palabra)  {
        cout << p << endl;
    }

    /* SALIDA

    Estas
    son
    cuatro
    palabras

    */

    return 0;
}

// Metodo para convertir un arreglo de caracteres a una cadena de caracteres
string convertToString(char* a, int size)
{
    // Declaracion de variables auxiliares
    string s = "";
    int i = 0;

    while(i <= size)  {
        s = s + *(a + i);  // Va concatenando las letras para formar una palabra
        i++;
    }

    return s;
}