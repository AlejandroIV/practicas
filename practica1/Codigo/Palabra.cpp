#include"Palabra.h"

// Constructores
Palabra::Palabra()
{
    frecuencia = 0;
    palabra = "";
}

Palabra::Palabra(char* charArray, int size)
{
    setPalabra(charArrayToString(charArray, size));
}

// Metodos setter y getter
void Palabra::setFrecuencia(int frecuencia)
{
    this->frecuencia = frecuencia;
}

int Palabra::getFrecuencia()
{
    return frecuencia;
}

void Palabra::incrementaFrecuencia()
{
    this->frecuencia++;
}

void Palabra::setPalabra(std::string palabra)
{
    this->palabra = palabra;
}

std::string Palabra::getPalabra()
{
    return palabra;
}

std::string Palabra::charArrayToString(char* a, int size)
{
    // Declaracion de variables auxiliares
    std::string s = "";
    int i = 0;

    while(i <= size)  {
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