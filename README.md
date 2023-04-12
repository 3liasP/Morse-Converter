# Morse-Converter
Simple C program that takes text input through stdio, converts the text to morse code and prints it.

## Description
This program reads text input from standard input using `fgets()`. It then converts each letter of the input to its Morse code representation, using a lookup table of Morse code strings for each letter and digit. The program adds separators between letters and words to make the output more readable. Finally, the program prints the Morse code output to standard output using `printf()`.

## Usage
To compile and run the program:

`$ gcc -Wall -std=c99 -pedantic morse_converter.c`
`$ ./a.out`

This will compile the program and run it. When prompted, enter the text you want to convert to Morse code. The program will then print the Morse code output to the terminal.
