all: encode decode hexConversion

# Encode program
encode: encode.o
	gcc encode.o -o encode

encode.o: encode.c
	gcc -c encode.c

# Decode program
decode: decode.o
	gcc decode.o -o decode

decode.o: decode.c
	gcc -c decode.c

# Hex Conversion program
hexConversion: hexConversion.o
	gcc hexConversion.o -o hex

hexConversion.o: hexConversion.c
	gcc -c hexConversion.c

# The clean will remove .o files
clean:
	rm *.o 
