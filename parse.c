#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
	char ** pArray = malloc(sizeof(char *) * 6);
 	char * str = line;
	for (int i = 0; i < 6; i++) {
		*(pArray + i) = strsep(&str , " ");
        }
        return pArray;
}

int main(int argc, char * argv[]){
    char line[] = "ls -a -l";
    char ** arr = parse_args(line);
    char * str = malloc((sizeof arr));
    for (int i = 0; *(arr + i); i++) {
        char * old = (str + i);
        strcpy((str + i), *(arr + i));
        printf("str used to be: %s\nNow it is:%s\n\n", old, (str + i));
    }
    execvp(&str[0], str);
    return 0;
}
