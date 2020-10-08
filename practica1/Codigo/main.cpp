#include"funcionesMain.h"

int main()
{
    // Agrega un caracter nulo al final del documento para evitar errores en el programa
    caracterFinal();

    // Declaracion de variable para almacenar el nombre del archivo
    char c[20];
    // Pide al usuario el nombre del archivo (input)
    cout << "Escribe el nombre del archivo de entrada con extension .'txt': ";
    cin >> c;

    // Declaracion de variable que contendra el vinculo al archivo de lectura
    ifstream archivoLeer;
    archivoLeer.open(c, ios::in);  // Abre el archivo en modo lectura para leer las palabras
    
    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoLeer.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    // Iniciacion del diccionario que almacenara las palabras de documento y su respectiva frecuencia
    vector<Palabra> diccionario = creaVectorFrecuencias(archivoLeer);
    archivoLeer.close();  // Cierra el archivo de lectura

    //imprimeFrecuencias(&diccionario);

    // Imprime la cantidad de palabras que hay en el "diccionario"
    cout << "Hay " << sumaFrecuencias(&diccionario) << " palabras en el diccionario" << endl;

    // Declaracion de variable que contendra el vinculo al archivo de escritura
    ofstream archivoEscribir;

    // Pide al usuario el nombre del archivo (output)
    cout << "Escribe el nombre del archivo de salida con extension .'txt': ";
    cin >> c;

    archivoEscribir.open(c, ios::out);  // Abre el archivo en modo escritura para escribir las palabras y su frecuencia

    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivoEscribir.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    // Bucle que se repetira mientras hayan elementos en el "diccionario"
    while(!(diccionario.empty()))  {
        // Manda a llamar a la funcion para ir escribiendo las palabras y su frecuencia, e irlas borrando del "diccionario"
        diccionario = escribeMayor(diccionario, archivoEscribir);
    }

    archivoEscribir.close();  // Cierra el archivo de escritura

    return 0;
}