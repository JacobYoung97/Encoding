#include<stdio.h>

#define BYTES_PER_LINE 24

int main() {

    int ch, bytes;
    
    bytes = 0;
    printf("START THE ENCODER v1.0\n");
    // Loops until the program is terminated or the EOF character is given
    while(1) {
        ch = fgetc(stdin);
        bytes++;
        
        // If run from command line without an input file, the EOF is the following:
        // Windows = CTRL+Z and Unix = CTRL+D
        if(ch == EOF)
            break;
        
        // Hexadecimal bytes encoded with XOR 0xAA for the input characters
        printf(" %02X", ch^0xAA);
        
        // If the output reaches the max bytes, then this will print it on a newline
        if(bytes == BYTES_PER_LINE) {
            putchar('\n');
            bytes = 0;
        }
    }
    printf("\nEND THE ENCODER\n");
    return(0);
    
}