#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int hexToInt(char *hex);
int charToInt(char h);

int main() {

    int v;
    // Only accepts length two like AA or B5
    char hex[3];

    hex[0] = (char)fgetc(stdin);
    hex[1] = (char)fgetc(stdin);
    hex[2] = '\0'; // End of string character

    v = hexToInt(hex);
    
    // These will convert the characters to uppercase for a nicer output
    hex[0] = toupper(hex[0]);
    hex[1] = toupper(hex[1]);
    
    // Prints in hex and the equivalent decimal representation
    printf("0x%s = %d\n", hex, v);

    return (0);
}

/**
 * hexToInt
 * This function will convert a hex string to the decimal representation
 * IN: char * - a character array/string of hex characters
 * OUT: int - the decimal representation of the hex string
 */
int hexToInt(char * hex) {
    int a, b;
    
    a = charToInt(hex[0]); // First character
    b = charToInt(hex[1]); // Second character
    
    // First digit is multiplied by 16 (left shifted 4 times)
    return((a << 4) + b);
}

/**
 * charToInt
 * This function will return a hex character's decimal representation
 * IN: char - a hex character (0-F)
 * OUT: int - the decimal representation of the hex character
 */
int charToInt(char h) {
	// Checks if the character is from 0 to 9
    if(isdigit(h)) {
        return(h - '0');
    }
    
    h = toupper(h);
    
    // If it is A to F then it is a hex character
    if(h >= 'A' && h <= 'F') {
        return(h - 'A' + 0x0A);
    } else {
        printf("\nInvalid hex character: %c\n", h);
        exit(1);
    }
    return (0);
}
