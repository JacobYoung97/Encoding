#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* This size is because we know how many bytes there are per line.
 * 24 bytes per line, each prefixed by a space and then a newline character.
 * (24 x 3) + 1
 */ 
#define LINE_LENGTH 73
#define TRUE 1
#define FALSE 0

void checkFile(char * line);
int processLine(char * line);
int charToInt(char h);

int main() {
	char line_buffer[LINE_LENGTH];
	char c;
	int buffer_index = 0;
	int first_line = TRUE;
	
	// Loops until the EOF character is found or the program is terminated
	while(1) {
		c = getchar();
		
		if(c == EOF)
			break;
		
		line_buffer[buffer_index] = c;
		buffer_index++;
		
		// Overflow condition
		if(buffer_index > LINE_LENGTH) {
			puts("\nInvalid hexcode line format");
			return(1);
		}
		if(c == '\n') {
			// terminate the string
			line_buffer[buffer_index] = '\0';
			
			// If it is the first line of the file, check the contents
			if(first_line) {
				checkFile(line_buffer);
				first_line = FALSE;
			} else {
				if(processLine(line_buffer))
					break;
			}
			
			// reset index
			buffer_index = 0;
		}
	}
	
	return (0);
}

/**
 * checkFile
 * This function checks to confirm the first line of the hex encoded file has the 
 * correct formating. If not, it has not been formatted by the encode program.
 * IN: char * - the first line of the file
 */
void checkFile(char * line) {
	if(strncmp(line, "START THE ENCODER v1.0", 22) == 0) {
		// Check version number here
		return;
	} else {
		puts("Improper hexcode file format");
		exit(1);
	}
}

/**
 * processLine
 * This function checks to confirm the last line of the hex encoded file has the 
 * correct formating. If it does, it returns true and the loop in main will break.
 * If not, then it will print the line.
 * IN: char * - the line of the file
 * OUT: int - TRUE (0) if the last line is found, and FALSE (1) if any other line is found
 */
int processLine(char * line) {
	int len, x, a, b, v;
	
	// If it is the last line of the file
	if(strncmp(line, "END THE ENCODER", 15) == 0) {
		return (TRUE);
	} else {
		// Gets the length of the bytes
		len = strlen(line) - 1;
		len /= 3;

		/* For every character on a line, we are indexing on a space. 
		 * So, the actual characters are 1 and 2 over 
		 */
		for(x = 0; x < len; x++) {
			// First character conversion
			a = charToInt(*(line + 1));
			// Second character conversion
			b = charToInt(*(line + 2));
			// Build value from the hexadecimal
			v = (a << 4) + b;
			
			// Puts the char decoded by AA (the same thing that was encoded by encode.c)
			putchar(v ^= 0xAA);
			line += 3;
		}

		return (FALSE);
	}
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
