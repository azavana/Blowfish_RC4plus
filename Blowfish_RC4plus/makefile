Main.exe : Blowfish.o RC4plus.o Main.o
		 c++ Blowfish.o RC4plus.o Main.o -o Main.exe

Blowfish.o : Blowfish.cpp Blowfish_RC4plus.h ORIG_S_P.h
		   c++ -c Blowfish.cpp

RC4plus.o : RC4plus.cpp Blowfish_RC4plus.h
		  c++ -c RC4plus.cpp

Main.o : Main.cpp Blowfish_RC4plus.h Colors.h ORIG_S_P.h
	    c++ -c Main.cpp
