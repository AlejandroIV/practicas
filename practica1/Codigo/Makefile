# Genera el programa
programa: main.o FuncionesMain.o LineaTexto.o Palabra.o
	g++ -o programa main.o FuncionesMain.o LineaTexto.o Palabra.o
	rm -f *.o

# Genera el codigo objeto de "main"
main.o: main.cpp FuncionesMain.h
	g++ -c main.cpp FuncionesMain.cpp

# Genera el codigo objeto de "main"
FuncionesMain.o: FuncionesMain.cpp FuncionesMain.h LineaTexto.cpp LineaTexto.h Palabra.cpp Palabra.h
	g++ -c FuncionesMain.cpp LineaTexto.cpp Palabra.cpp

# Genera el codigo objeto de "main"
LineaTexto.o: LineaTexto.cpp LineaTexto.h
	g++ -c LineaTexto.cpp

# Genera el codigo objeto de "main"
Palabra.o: Palabra.cpp Palabra.h
	g++ -c Palabra.cpp

clean:
	rm -f programa *.o