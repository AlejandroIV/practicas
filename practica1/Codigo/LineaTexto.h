#pragma once

class LineaTexto
{
    private:
        char* charArray;

    public:
        LineaTexto();
        LineaTexto(char charArray[]);
        void setCharArray(char* charArray);
        char* getCharArray();
        char* getCharArray(int indice);
};