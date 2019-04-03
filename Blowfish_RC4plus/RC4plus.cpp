/* RC4+ */

#include <iostream>
#include <new>
#include <cstring>
#include "Blowfish_RC4plus.h"

using namespace std;

/* Key scheduling algorithm */
void Blowfish_RC4plus::KSA (uchar *key, uchar *S)
{
	for (int i = 0; i < 256; i++)
		S[i] = i;

	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		j = (j + S[i] + key[i % strlen((const char*)key)]) % 256;
		swap (S[i],S[j]);
	}
	return;
}

/* Pseudo random generation algorithm */
void Blowfish_RC4plus::PRGA_RC4plus (uchar *S, uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j = 0;

	for (int n = 0; n < strlen((const char*)plaintext); n++)
	{
		i = (i+1) % 256;
		j = (j+S[i]) % 256;

		swap (S[i],S[j]);

		int c = (S[(i <<= 5)^(j >>= 3)] + S[(j <<= 5)^(i >>= 3)]) % 256;
		int K = ((S[(S[i]+S[j]) % 256] + S[c^0xAA]) % 256)^S[(j+S[j]) % 256];		

		ciphertext[n] = K^plaintext[n];
	}
	return;
}

void Blowfish_RC4plus::RC4plus_Encrypt (uchar *plaintext, uchar *RC4plus_key, uchar *ciphertext)
{
	uchar S[256];
	KSA (RC4plus_key, S);
	PRGA_RC4plus (S, plaintext, ciphertext);
	
	return;
}

uchar *Blowfish_RC4plus::RC4plus_key()
{
	srand(time(NULL));
	int key1, key2, count;
	int len_key = rand() % 256 + 5; // Key between 5 to 256 bytes long

	uchar *result = new (nothrow) uchar[len_key];

	for (int i = 0; i < len_key; i++)
	{
		count = rand() % 2;
		key1 = rand() % 26;
		key2 = rand() % 26;

		if (count == 0)
			result[i] = (char)((key1 - 65) % 26 + 65);
		else 
			result[i] = (char)((key2 - 97) % 26 + 97);
	}
	return result;
}

// Destructor
Blowfish_RC4plus::~Blowfish_RC4plus(void){ };
