/**
 * @file Palabra.h
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 10/10/2020
 */

#pragma once

#include<string>
#include<iostream>

class Palabra
{
    private:
        int frecuencia;
        std::string palabra;
    
    public:
        /**
         * @brief Constructor de la clase "Palabra"
         */ 
        Palabra();
        /**
         * @brief Constructor de la clase "Palabra"
         * @param charArray Puntero a "char"
         * @param final Cantidad de caracteres que hay en la palabra
         */ 
        Palabra(char* charArray, int final);

        /**
         * @brief Metodo setter de la variable de instancia "frecuencia" del objeto
         * @param frecuencia Cantidad de palabras iguales
         */ 
        void setFrecuencia(int frecuencia);
        /**
         * @brief Metodo getter de la variable de instancia "frecuencia" del objeto
         * @return int
         */ 
        int getFrecuencia();
        /**
         * @brief Metodo setter de la variable de instancia "palabra" del objeto
         * @param palabra Palabra de tipo "string"
         */ 
        void setPalabra(std::string palabra);
        /**
         * @brief Metodo getter de la variable de instancia "palabra" del objeto
         * @return std::string
         */ 
        std::string getPalabra();

        /**
         * @brief Metodo que incrementa la frecuencia de la "Palabra" en 1
         */ 
        void incrementaFrecuencia();
        /**
         * @brief Metodo para convertir un arreglo de caracteres a una cadena
         * @param a Puntero a "char"
         * @param final Cantidad de caracteres que hay en la palabra
         * @return std::string
         */ 
        std::string charArrayToString(char* a, int final);
        /**
         * @brief Metodo para saber si dos palabras son iguales
         * @param p Objeto de tipo "Palabra"
         * @return bool
         */ 
        bool esIgual(Palabra p);
        /**
         * @brief Funcion que regresa true si el caracter es una letra
         * @param l Puntero a "char"
         * @return bool
         */
        bool esLetra(char* l);
        /**
         * @brief Funcion que regresa true si la letra es mayuscula
         * @param l Puntero a "char"
         * @return bool
         */
        bool esMayuscula(char* l);
};