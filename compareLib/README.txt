Embarcados Tutorial DLL

1. Instalar Mingw:

sudo apt-get install gcc-mingw-w64

2. Gerando os arquivos objetos:

/usr/bin/i686-w64-mingw32-gcc -IInc Src/*.c -c -fpic -o Obj/compare.o

3. Gerando executável:

/usr/bin/i686-w64-mingw32-gcc -shared -o Bin/compare.dll Obj/compare.o

