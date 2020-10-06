#pragma once

#include<string>

class Palabra
{
    private:
        int numElem;
        int frecuencia;
        std::string palabra;
    
    public:
        Palabra();
        Palabra(char* charArray, int final);

        void setFrecuencia(int frecuencia);
        int getFrecuencia();
        void setPalabra(std::string palabra);
        std::string getPalabra();
        void setNumElem(std::string palabra);
        int getNumElem();

        void incrementaFrecuencia();
        std::string charArrayToString(char* a, int final);
        bool esIgual(Palabra p);
};