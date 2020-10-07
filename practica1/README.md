# Problema:
El programa debe ser capaz de leer un archivo de texto, contar la cantidad de veces que aparece cada palabra y escribir en otro archivo diccionario de todas las palabras ordenadas de mayor frecuencia a menor frecuencia.

# Diseño del algoritmo:
Tomando en cuenta el código de ejemplo en Python.
> 1. Crea un vínculo al documento de texto de lectura (donde esta el texto que se analizará).
> 2. Declara el "diccionario" que contendrá las palabras y su frecuencia.
> 3. Bucle que recorrerá cada linea del documento.
>    - Descompone la linea en una lista de palabras.
>    - Bucle que recorrerá cada palabra del documento.
>      - Si la palabra ya está en el diccionario, entonces aumenta su frecuencia.
>      - Pero sino, la agrega y establece su frecuencia en 1.
> 4. Acomoda las palabras del diccionario de manera descendete dependiendo de su frecuencia.
> 5. Crea un vínculo al documento de texto de escritura (donde se almacenarán las palabras y su frecuencia de forma descendente).
> 6. Copia todas las palabras del diccionario (una vez acomodados) dentro del documento.