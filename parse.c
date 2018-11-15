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
    char ** args = parse_args(line);
    execvp(args[0], args);
		free(args);
    return 0;
}
