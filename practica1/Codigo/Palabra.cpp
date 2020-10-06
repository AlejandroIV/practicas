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

    while(i <= final)  {
        s = s + *(a + i);  // Va concatenando las letras para formar una palabra
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