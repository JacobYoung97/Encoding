#include<stdio.h>

int main() {

    int ch;
    
    while(1) {
        ch = fgetc(stdin);
        
        if(ch == EOF)
            break;
        
        printf("%02X", ch^0xAA);
    }
    
    return(0);
    
}