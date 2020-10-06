# Problema:
El programa debe ser capaz de leer un archivo de texto, contar la cantidad de veces que aparece cada palabra y escribir en otro archivo diccionario de todas las palabras ordenadas de mayor frecuencia a menor frecuencia.

# Diseño del algoritmo:
Tomando en cuenta el código en Python, el algoritmo será el siguiente:
> 1. Pedir al usuario que ingrese un texto.
> 2. Descomponer el texto en palabras.
> 3. Guardar las palabras en una lista.
> 4. Declarar el diccionario cuyos elementos son pares de datos: palabra y contador.
> 5. Iterar la lista de lista de palabras y
>     - Si la palabra no existe en el diccionario, añade la palabra y establece el contador en 1.
>     - Si la palabra ya existe en el diccionario, incrementa el valor del contador en 1.
> 6. Imprimir las palabras con la frecuencia en la que aparecen.
