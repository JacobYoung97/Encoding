#ifndef __ENCODEDECODE_H__
#define __ENCODEDECODE_H__

#define BYTES_PER_LINE 24
#define LINE_LENGTH BYTES_PER_LINE * 3 + 1
#define TRUE 1
#define FALSE 0

// The specific encoding macros
#define ENCODING 0xAA
#define OPENING "START THE ENCODER v1.0"
#define CLOSING "END THE ENCODER"

/**
 * checkFile
 * This function checks to confirm the first line of the hex encoded file has the 
 * correct formating. If not, it has not been formatted by the encode program.
 * IN: char * - the first line of the file
 */
void checkFile(char * line);

/**
 * processLine
 * This function checks to confirm the last line of the hex encoded file has the 
 * correct formating. If it does, it returns true and the loop in main will break.
 * If not, then it will decode the line.
 * IN: char * - the line of the file
 * OUT: int - TRUE (0) if the last line is found, and FALSE (1) if any other line is found
 */
int processLine(char * line);

/**
 * charToInt
 * This function will return a hex character's decimal representation
 * IN: char - a hex character (0-F)
 * OUT: int - the decimal representation of the hex character
 */
int charToInt(char h);

#endif
