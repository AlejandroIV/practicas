#pragma once

// incluye todas las bibliotecas necesarias para el proyecto
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include"LineaTexto.h"
#include"Palabra.h"

using namespace std;

/** 
 * @brief Funcion que agrega un caracter nulo al final del archivo de texto que se va a leer
 */ 
void caracterFinal(char archivo[20]);
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
/**
 * @brief Funcion que escribe en el documento de escritura la cabecera de una tabla
 */ 
void empiezaTabla(ofstream &archivoWrite);
/**
 * @brief Funcion que escribe una linea de 43 caracteres en el archivo de texto que toma como parametro
 */ 
void escribeLinea(ofstream &archivoWrite);
/**
 * @brief Funcion que recorre un "diccionario", escribe en un documento de texto la primera palabra cuya frecuencia sea mayor
 * y elimina ese elemento del diccionario
 * @param dic Vector de tipo "Palabra"
 * @param archivoWrite Puntero a "ofstream"
 * @return vector<Palabra>
 */
vector<Palabra> escribeMayor(vector<Palabra> dic, ofstream &archivoWrite);