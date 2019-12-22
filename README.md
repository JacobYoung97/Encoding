# Encoding

This is a basic program that will encode/decode some text given to it. I am following the tutorial given in the description.
However, I am changing some of the text to have a slightly better look to the code itself.

## Real World Applications
Storing files in plaintext/human readable format is never a good option for data. This program does a basic encoding of the data so it is not as easily readable.  
However, this is not encryption so the encoding is known and can be decoded easier than text that is encrypted.

In order for this to be a bit safer to encode data with, the values related to encoding in the header file would be hidden.  
Either the header file is not made public, or the values are changed at a frequent rate to avoid possible decoding.

## Usage
To compile the programs, type `make`.  
To clean the directory of .o files, type `make clean`. 
  
Create a text file with the words you would like encoded.  

To encode it, run the encode program like:  
`./encode < [fileCreated] > [destinationFile]`  

This will take the text you wrote and output it into another file for later decoding.  
  
To decode the file, run the decode program like:  
`./decode < [destinationFile]`.  

The "destinationFile" is the same one as was run with the encoding program.  
This will output the file contents decoded to the screen.  

Some samples can be found in the samples folder.

## Version history
### Basic Input Version (non-pretty output)
[First version: commit #3f48beb3561deb1a0f50797e96faf3175739128b](https://github.com/JacobYoung97/Encoding/commit/3f48beb3561deb1a0f50797e96faf3175739128b)

### Basic Input Version (formatted output)
[Second version: commit #61eefc7b476fd99e7120cade5f737aef4603e445](https://github.com/JacobYoung97/Encoding/commit/61eefc7b476fd99e7120cade5f737aef4603e445)

### First hex decoding (hex to decimal)
[Third version: commit #88fc79bc94322ab1488cd726cc08c850739a6ed3](https://github.com/JacobYoung97/Encoding/commit/88fc79bc94322ab1488cd726cc08c850739a6ed3)

### Second hex decoding (prints hex formatted with the encoder)
[Fourth version: commit #ff5b9c5ee09ba652bc4d4551367a3de2d0eedf9a](https://github.com/JacobYoung97/Encoding/commit/ff5b9c5ee09ba652bc4d4551367a3de2d0eedf9a)

### Third hex decoding (checks contents of first line for security)
[Fifth version: commit #941e947fe887b6c6d0e1960193b7a6137bcbef04](https://github.com/JacobYoung97/Encoding/commit/941e947fe887b6c6d0e1960193b7a6137bcbef04)

### Fourth hex decoding (checks contents of the last line)
[Sixth version: commit #bdc7c3615f6547bdf63c26e11ee5b4cfc1e143b5](https://github.com/JacobYoung97/Encoding/commit/bdc7c3615f6547bdf63c26e11ee5b4cfc1e143b5)

### Fifth (and final tutorial) decoding (actually decodes what encode does)
[Seventh version: commit #95f292fed96ca330412be8eb953947242844b551](https://github.com/JacobYoung97/Encoding/commit/95f292fed96ca330412be8eb953947242844b551)

### Header file version (updates to make it easier to change on the fly)
[Eighth version: commit #c0352e68447d7aa3e79c6ba1bd785fa26e77f8c7](https://github.com/JacobYoung97/Encoding/commit/c0352e68447d7aa3e79c6ba1bd785fa26e77f8c7)

