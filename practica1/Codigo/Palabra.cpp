#include"Palabra.h"

// Constructores
Palabra::Palabra()
{
    frecuencia = 0;
    palabra = "";
}

Palabra::Palabra(char* charArray, int final)
{
    setPalabra(charArrayToString(charArray, final));
    frecuencia = 0;
}

void Palabra::setFrecuencia(int frecuencia)
{
    this->frecuencia = frecuencia;
}

int Palabra::getFrecuencia()
{
    return frecuencia;
}

void Palabra::setPalabra(std::string palabra)
{
    this->palabra = palabra;
}

std::string Palabra::getPalabra()
{
    return palabra;
}

void Palabra::incrementaFrecuencia()
{
    this->frecuencia++;
}

std::string Palabra::charArrayToString(char* a, int final)
{
    // Declaracion de variables auxiliares
    std::string s = "";
    int i = 0;
    int c = 0;

    while(i <= final)  {
        // Condicional para contar solo las letras mayusculas, minusculas y los numeros
        if(esLetra(a + i))  {
            // Condicional para saber si la letra es mayuscula
            if(esMayuscula(a + i))  {
                s += (*(a + i) + 32);  // Concatena la letra minuscula
            }
            else  {
                s += *(a + i);  // Va concatenando las letras para formar una palabra
            }
        }// Condicional para cambiar las letras que tienen acento a letras sin acento
        else  {
            switch(*(a + i))  {
                case -95:  // á
                    s += 'a';
                    break;
                case -87:  // é
                    s += 'e';
                    break;
                case -83:  // í
                    s += 'i';
                    break;
                case -77:  // ó
                    s += 'o';
                    break;
                case -70:  // ú
                    s += 'u';
                    break;
                case -127:  // Á
                    s += 'a';
                    break;
                case -119:  // É
                    s += 'e';
                    break;
                case -115:  // Í
                    s += 'i';
                    break;
                case -109:  // Ó
                    s += 'o';
                    break;
                case -102:  // Ú
                    s += 'u';
                    break;
            }
        }
        
        i++;
    }

    return s;
}

bool Palabra::esIgual(Palabra p)
{
    if(this->palabra == p.palabra)  {
        return true;
    }

    return false;
}

bool Palabra::esLetra(char* l)
{
    // Condicional para revisar si el caracter es numero o letra
    if(((*(l) >= 48) && (*(l) <= 57)) || ((*(l) >= 65) && (*(l) <= 90)) || ((*(l) >= 97) && (*(l) <= 122)))  {
        return true;
    }
    // Si es otro caracter regresara false
    return false;
}

bool Palabra::esMayuscula(char* l)
{
    // Condicional para revisar si la letra es mayuscula
    if((*(l) >= 65) && (*(l) <= 90))  {
        return true;
    }
    // Si la letra es minuscula regresara false
    return false;
}