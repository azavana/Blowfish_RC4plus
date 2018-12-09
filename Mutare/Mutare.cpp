/* Andry RAFAM ANDRIANJAFY - December 2018

Mutare encryption program : Blowfish and RC4+. Linux Ubuntu 16.04 LTS

GCC 6.5.0 && GDB 8.2 */

#include <iostream>
#include <new>
#include <cstdint>
#include <cstring>
#include "Mutare.h"
#include "Colors.h"
#include "ORIG_S_P.h"

using namespace std;

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "\nUsage : %s < Plaintext >\n\n", argv[0]);
		return -1;
	}

	Mutare *M = new (nothrow) Mutare;	
	
	uint32_t L, R;
	uint64_t C;
	int block_len;	
	uchar *rc4_plus = new (nothrow) uint8_t[strlen(argv[1])];

	fprintf(stdout, Cyan "\n\t***************************************************");
	fprintf(stdout, Red "\n\t\t[ MUTARE ( Blowfish and RC4+ ) ]");	
	fprintf(stdout, Cyan "\n\t***************************************************");		
	fprintf(stdout, Yellow "\n\n\t[ RC4+ and Blowfish keys generated randomly ... ]");
	fprintf(stdout, Reset);	

	int len_RC4plus_key = strlen((const char*)M->RC4plus_key());
	uchar *key_temp_RC4plus = new (nothrow) uchar[len_RC4plus_key];
	memcpy (key_temp_RC4plus, M->RC4plus_key(), len_RC4plus_key);	

	/* Performing RC4+ */
	M->RC4plus_Encrypt ((uchar*)argv[1], key_temp_RC4plus, rc4_plus);
	int rc4_plus_len = strlen((const char*)rc4_plus);
	fprintf(stdout, "\n\n\t<< Encryption with RC4+ ... Done. >> ");
	
	int len_Blowfish_key = strlen((const char*)M->Blowfish_key());
	uchar *key_temp_Blowfish = new (nothrow) uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, M->Blowfish_key(), len_Blowfish_key);

	/* Performing Blowfish */
	M->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	M->crack_text (rc4_plus, &L, &R, rc4_plus_len); // Crack the text string into two 32-bit block; pad with zeros if necessary
	M->Blowfish_Encipher (&L, &R);
		
	fprintf(stdout, Green  "\n\n\t[ MUTARE ]");	
	fprintf(stdout, Reset " >> %08X %08X\n\n\n", L, R);	
	
	delete [ ] rc4_plus;
	delete M;
	
	return EXIT_SUCCESS;
}
