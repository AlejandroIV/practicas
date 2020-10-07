#include"funcionesMain.h"

int main()
{
    // Agrega un caracter nulo al final del documento para evitar errores en el programa
    caracterFinal();

    // Declaracion de variable para almacenar el nombre del archivo
    char c[20];
    // Pide al usuario el nombre del archivo
    cout << "Escribe el nombre del archivo con extension .'txt': ";
    cin >> c;

    // Declaracion de variable que contendra el vinculo al archivo de lectura
    ifstream archivoLeer;
    archivoLeer.open(c, ios::in);  // Abre el archivo en modo lectura para leer las palabras
    
    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoLeer.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    /* Iniciacion del diccionario que almacenara "Palabras", por lo tanto, almacenara elementos que seran palabras y su frecuencia
    para eso manda a llamar a la  */
    vector<Palabra> diccionario = creaVectorFrecuencias(archivoLeer);
    archivoLeer.close();  // Cierra el archivo de lectura

    //imprimeFrecuencias(&diccionario);

    cout << "Hay " << sumaFrecuencias(&diccionario) << " palabras en el diccionario" << endl;

    // Declaracion de variable que contendra el vinculo al archivo de escritura
    ofstream archivoEscribir;

    archivoEscribir.open("palabras_frecuencias.txt", ios::out);  // Abre en modo escritura para escribir las palabras y su frecuencia

    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoEscribir.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    // Bucle que se repetira mientras hayan elementos en el "diccionario"
    while(!(diccionario.empty()))  {
        diccionario = escribeMayor(diccionario, archivoEscribir);
    }

    archivoEscribir.close();  // Cierra el archivo de escritura

    return 0;
}