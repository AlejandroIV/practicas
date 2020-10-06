#pragma once

#include<string>

class LineaTexto
{
    private:
        char* linea;

    public:
        LineaTexto();
        LineaTexto(char* linea);

        void setCharArray(char* linea);
        char* getCharArray();
        char* getCharArray(int indice);
};