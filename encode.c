#include<stdio.h>
#include "encodeDecode.h"

int main() {

    int ch, bytes;
    
    bytes = 0;
    printf(OPENING"\n");
    // Loops until the program is terminated or the EOF character is given
    while(1) {
        ch = fgetc(stdin);
        bytes++;
        
        // If run from command line without an input file, the EOF is the following:
        // Windows = CTRL+Z and Unix = CTRL+D
        if(ch == EOF)
            break;
        
        // Hexadecimal bytes encoded with XOR 0xAA for the input characters
        printf(" %02X", ch^ENCODING);
        
        // If the output reaches the max bytes, then this will print it on a newline
        if(bytes == BYTES_PER_LINE) {
            putchar('\n');
            bytes = 0;
        }
    }
    printf("\n"CLOSING"\n");
    return(0);
    
}
