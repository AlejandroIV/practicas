#pragma once

#include<string>
#include<iostream>

class LineaTexto
{
    private:
        char* linea;

    public:
        /**
         * @brief Constructor de la clase "LineaTexto"
         */ 
        LineaTexto();
        /**
         * @brief Constructor de la clase "LineaTexto"
         * @param linea Puntero a "char"
         */ 
        LineaTexto(char* linea);

        /**
         * @brief Metodo setter de la variable de instancia "linea" del objeto
         * @param linea Puntero a "char"
         */ 
        void setCharArray(char* linea);
        /**
         * @brief Metodo getter de la variable de instancia "linea" del objeto
         * @return Puntero a "char"
         */ 
        char* getCharArray();
        /**
         * @brief Metodo getter de la variable de instancia "linea" del objeto
         * @param indice Punto de partida de un arreglo
         * @return Puntero a "char"
         */ 
        char* getCharArray(int indice);
};