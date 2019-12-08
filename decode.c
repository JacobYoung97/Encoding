#include <stdio.h>

/* This size is because we know how many bytes there are per line.
 * 24 bytes per line, each prefixed by a space and then a newline character.
 * (24 x 3) + 1
 */ 
#define LINE_LENGTH 73

int main() {
	char line_buffer[LINE_LENGTH];
	char c;
	int buffer_index = 0;
	
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
			
			// display contents 
			printf("%s", line_buffer);
			
			// reset index
			buffer_index = 0;
		}
	}
	
	return (0);
}
