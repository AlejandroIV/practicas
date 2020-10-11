/**
 * @file LineaTexto.cpp
 * 
 * Implementacion de la clase "LineaTexto" para usar con la biblioteca "LineaTexto.h".
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 10/10/2020
 */ 

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