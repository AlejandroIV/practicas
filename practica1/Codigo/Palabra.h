#pragma once

#include<string>

class Palabra
{
    private:
        int frecuencia;
        std::string palabra;
    
    public:
        Palabra();
        Palabra(char* charArray, int size);
        void setFrecuencia(int frecuencia);
        int getFrecuencia();
        void incrementaFrecuencia();
        void setPalabra(std::string palabra);
        std::string getPalabra();
        std::string charArrayToString(char* a, int size);
        bool esIgual(Palabra p);
};