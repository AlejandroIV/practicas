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

// Metodos setter y getter para la variable "frecuencia"
void Palabra::setFrecuencia(int frecuencia)
{
    this->frecuencia = frecuencia;
}

int Palabra::getFrecuencia()
{
    return frecuencia;
}

// Metodos setter y getter para la variable "palabra"
void Palabra::setPalabra(std::string palabra)
{
    this->palabra = palabra;
}

std::string Palabra::getPalabra()
{
    return palabra;
}

// Metodo que incrementa la frecuencia de la "Palabra" en 1
void Palabra::incrementaFrecuencia()
{
    this->frecuencia++;
}

// Metodo para convertir un arreglo de caracteres a una cadena
std::string Palabra::charArrayToString(char* a, int final)
{
    // Declaracion de variables auxiliares
    std::string s = "";
    int i = 0;

    while(i <= final)  {
        s = s + *(a + i);  // Va concatenando las letras para formar una palabra
        i++;
    }

    return s;
}

// Metodo para saber si dos palabras son iguales
bool Palabra::esIgual(Palabra p)
{
    if(this->palabra == p.palabra)  {
        return true;
    }

    return false;
}