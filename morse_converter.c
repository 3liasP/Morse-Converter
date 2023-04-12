#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 4096

// Every character and number in morse code, 36 in total
const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};
// All alphabets are in lowercase! Uppercase characters will be converted.
const char *alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
// We use "/" as a word separator, as it increases readability
const char *morse_separator = " / ";
// Single letters will be separated with just one space
const char *letter_separator = " ";

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH] = "";
    // Read input from stdin, user input
    printf("Enter text to convert to Morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Converting the given input to Morse code
    int output_pos = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        // Convert uppercase letters to lowercase
        char c = tolower(input[i]);
        if (c == ' ') {
            // Add a separator for word boundaries
            strcat(output, morse_separator);
            output_pos += strlen(morse_separator);
        } else {
            // Find the index of the letter in the alphabet
            const char *letter_pos = strchr(alphabet, c);
            if (letter_pos != NULL) {
                int index = letter_pos - alphabet;
                // Append the Morse code for the letter
                strcat(output, morse_code[index]);
                output_pos += strlen(morse_code[index]);
                // Add a separator for letter boundaries
                if (input[i+1] != '\0' && input[i+1] != ' ') {
                    strcat(output, letter_separator);
                    output_pos += strlen(letter_separator);
                }
            }
        }
    }
    // Finally, print the Morse code output
    printf("%s\n", output);
    return 0;
}
