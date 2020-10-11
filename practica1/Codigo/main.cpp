/**
 * 
 * Codigo en C++ de programa que lee un archivo de texto y escribe en otro archivo de
 * texto las frecuencias de las palabras ordenadas de forma descendente en una tabla.
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 10/10/2020
 */ 

#include"funcionesMain.h"

int main()
{
    // Declaracion de variable para almacenar el nombre del archivo
    char c[25] = "";

    // Pide al usuario el nombre del archivo (input)
    cout << "Escribe el nombre del archivo de entrada con extension .'txt' (limite de caracteres: 25)" << endl;
    cout << "Si no sabe que escribir, entonces digite '0' y presione enter, y el programa leera el documento 'texto.txt' si es que existe" << endl;
    cin >> c;
    // Condicional para comprobar el nombre del documento dado por el usuario
    if(c[0] == '0')  {
        strcpy(c, "texto.txt");
    }

    // Agrega un caracter nulo al final del documento para evitar errores en el programa
    caracterFinal(c);

    // Declaracion de variable que contendra el vinculo al archivo de lectura
    ifstream archivoLeer;
    archivoLeer.open(c, ios::in);  // Abre el archivo en modo lectura para leer las palabras
    
    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoLeer.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    // Iniciacion del diccionario que almacenara las palabras de documento y su respectiva frecuencia
    vector<Palabra> diccionario;
    // Manda a llamar a la funcion para crear el diccionario con las palabras y su respectiva frecuencia
    creaVectorFrecuencias(archivoLeer, diccionario);
    archivoLeer.close();  // Cierra el archivo de lectura

    // Manda a llamar a la funcion para imprimir las palabras y su respectiva frecuencia
    //imprimeFrecuencias(&diccionario);

    // Imprime la cantidad de palabras que hay en el "diccionario"
    cout << "Hay " << sumaFrecuencias(&diccionario) << " palabras en el diccionario" << endl;

    // Declaracion de variable que contendra el vinculo al archivo de escritura
    ofstream archivoEscribir;

    // Pide al usuario el nombre del archivo (output)
    cout << "Escribe el nombre del archivo de salida con extension .'txt' (limite de caracteres: 25)" << endl;
    cout << "Si no sabe que escribir, entonces digite '0' y presione enter, y el programa escribira las frecuencias de las palabras en el documento 'frecuencias_palabras.txt'" << endl;
    cin >> c;
    // Condicional para comprobar el nombre del documento dado por el usuario
    if(c[0] == '0')  {
        strcpy(c, "frecuencias_palabras.txt");
    }

    archivoEscribir.open(c, ios::out);  // Abre el archivo en modo escritura para escribir las palabras y su frecuencia

    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoEscribir.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    // Manda a llamar a la funcion para escribir la cabecera de la tabla en el documento de escritura
    empiezaTabla(archivoEscribir);

    // Bucle que se repetira mientras hayan elementos en el "diccionario"
    while(!(diccionario.empty()))  {
        // Manda a llamar a la funcion para ir escribiendo las palabras y su frecuencia, e irlas borrando del "diccionario"
        escribeMayor(diccionario, archivoEscribir);
    }

    // Agrega una linea de 43 caracteres al final de la tabla
    escribeLinea(archivoEscribir);

    archivoEscribir.close();  // Cierra el archivo de escritura

    return 0;
}