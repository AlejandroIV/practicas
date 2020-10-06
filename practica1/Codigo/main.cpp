#include"funcionesMain.h"

int main()
{
    // Agrega un caracter nulo al final del documento para evitar errores en el programa
    caracterFinal();

    // Declaracion de variable que contendra el vinculo al archivo
    ifstream archivo;
    archivo.open("ejemplo.txt", ios::in);  // Abre el archivo en modo lectura
    
    // Condicional para comprobar si se abrio el archivo de texto adecuadamente
    if(archivo.fail())  {
        cout << "Error! No se pudo abrir el archivo";
        exit(1);
    }

    /* Iniciacion del diccionario que almacenara "Palabras", por lo tanto, almacenara elementos que seran palabras y su frecuencia
    para eso manda a llamar a la  */
    vector<Palabra> diccionario = creaVectorFrecuencias(archivo);
    archivo.close();  // Cierra el archivo

    return 0;
}