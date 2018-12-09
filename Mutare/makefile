Mutare.exe : Blowfish.o RC4plus.o Mutare.o
			g++ Blowfish.o RC4plus.o Mutare.o -o Mutare.exe
Blowfish.o : Blowfish.cpp Mutare.h ORIG_S_P.h
		   g++ -c Blowfish.cpp
RC4plus.o : RC4plus.cpp Mutare.h
		  g++ -c RC4plus.cpp
Mutare.o : Mutare.cpp Mutare.h Colors.h ORIG_S_P.h
		   g++ -c Mutare.cpp
