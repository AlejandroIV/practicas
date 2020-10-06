#include"LineaTexto.h"

using namespace std;

// Constructores
LineaTexto::LineaTexto()
{
    linea = NULL;
}

LineaTexto::LineaTexto(char* linea)
{
    this->linea = linea;
}

void LineaTexto::setCharArray(char* linea)
{
    this->linea = linea;
}

char* LineaTexto::getCharArray()
{
    return linea;
}

char* LineaTexto::getCharArray(int indice)
{
    return linea + indice;
}