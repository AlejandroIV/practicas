#include<vector>
#include<string>
#include<iostream>
#include"LineaTexto.h"

using namespace std;

// Constructores
LineaTexto::LineaTexto()
{
    charArray = NULL;
}

LineaTexto::LineaTexto(char charArray[])
{
    this->charArray = charArray;
}

// Metodos setter y getter
void LineaTexto::setCharArray(char* charArray)
{
    this->charArray = charArray;
}

char* LineaTexto::getCharArray()
{
    return charArray;
}

char* LineaTexto::getCharArray(int indice)
{
    return charArray + indice;
}