#pragma once

// incluye todas las bibliotecas necesarias para el proyecto
#include<vector>
#include<fstream>
#include<cstring>
#include"LineaTexto.h"
#include"Palabra.h"

using namespace std;

/** 
 * @brief Funcion que agrega un caracter nulo al final del archivo de texto que se va a leer
 */ 
void caracterFinal();
/** 
 * @brief Funcion que leera todo el documento de texto que tome como parametro y regresara un vector con las palabras y su frecuencia
 * @param archivoRead Puntero a "ifstream"
 * @return vector<Palabra>
 */ 
vector<Palabra> creaVectorFrecuencias(ifstream &archivoRead);
/**
 * @brief Funcion que imprime las frecuencias de un "diccionario"
 * @param dic Puntero a un vector de tipo "Palabra"
 */
void imprimeFrecuencias(vector<Palabra>* dic);
/**
 * @brief Funcion que regresa la suma de las frecuencias de las "Palabras" que hay en un "diccionario"
 * @param dic Puntero a un vector de tipo "Palabra"
 * @return int
 */
int sumaFrecuencias(vector<Palabra>* dic);