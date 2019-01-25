# Blowfish_RC4plus
Lightweight encryption program based on Blowfish and RC4+.

# How it works

- Generate RC4+ and Blowfish keys randomly
- Encrypt with RC4+ first
- Performs Blowfish over RC4+
- Returns the result in hexadecimal value - 64 bits long

# Files included

- ORIG_S_P.h -> File which contains the original Shift boxes and Permutation boxes
- Blowfish_RC4plus.h -> Header file
- Colors.h -> Some color used in the program
- Blowfish.cpp -> Implementation of Blowfish
- RC4plus.cpp -> Implementation of RC4+
- Main.cpp -> The Main program
- Makefile -> GNU Make
