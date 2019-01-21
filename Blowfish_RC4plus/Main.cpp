/* Andry RAFAM ANDRIANJAFY

Release : December 2018 (Updated January 2019)

BLOWFISH_RC4plus encryption program in C++: Blowfish and RC4+. Linux Ubuntu 16.04 LTS

GCC 6.5.0 && GDB 8.2 */

#include <iostream>
#include <new>
#include <cstdint>
#include <cstring>
#include "Blowfish_RC4plus.h"
#include "Colors.h"
#include "ORIG_S_P.h"

using namespace std;

main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "\nUsage : %s < Plaintext >\n\n", argv[0]);
		exit(0);
	}
	Blowfish_RC4plus *B = new (nothrow) Blowfish_RC4plus;	
	
	uint32_t L, R;
	uint64_t C;
	int block_len;	
	uchar *rc4_plus = new (nothrow) uint8_t[strlen(argv[1])];

	system("clear");
	
	fprintf(stdout, Cyan "\n\t***************************************************");
	fprintf(stdout, Red "\n\t\t[ BLOWFISH_RC4+ ( Blowfish and RC4+ ) ]");	
	fprintf(stdout, Cyan "\n\t***************************************************");		
	fprintf(stdout, Reset);	
	fprintf(stdout,"\n\n\t [ Your input text ] >> %s ",argv[1]);
	fprintf(stdout, Yellow "\n\n\t[ RC4+ AND BLOWFISH GENERATED RANDOMLY ... ]");
	fprintf(stdout, Reset);	

	int len_RC4plus_key = strlen((const char*)B->RC4plus_key());
	uchar *key_temp_RC4plus = new (nothrow) uchar[len_RC4plus_key]; // Use of intermediate variable to store the RC4plus_key, randomly generated
	memcpy (key_temp_RC4plus, B->RC4plus_key(), len_RC4plus_key); // Copy the RC4plus_key to key_temp_RC4plus

	/* Performing RC4+ */
	B->RC4plus_Encrypt ((uchar*)argv[1], key_temp_RC4plus, rc4_plus);
	int rc4_plus_len = strlen((const char*)rc4_plus);
	fprintf(stdout, "\n\n\t<< FIRST STAGE : Encryption with RC4+ ... DONE !!!. >> ");
	
	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new (nothrow) uchar[len_Blowfish_key]; // Use of intermediate variable to store the Blowfish_key, randomly generated
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key); // Copy the Blowfish_key to key_temp_Blowfish

	/* Performing Blowfish */
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text (rc4_plus, &L, &R, rc4_plus_len); // Crack the text string into two 32-bit block; pad with zeros if necessary
	B->Blowfish_Encipher (&L, &R);
		
	fprintf(stdout, Green  "\n\n\t[ FINAL STAGE ] >> ");	
	fprintf(stdout, Reset "%08X %08X\n\n\n", L, R);	
	
	delete [ ] key_temp_RC4plus;
	delete [ ] key_temp_Blowfish;
	delete [ ] rc4_plus;
	delete B;
}
