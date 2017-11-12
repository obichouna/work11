#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char * line){
  char **args = (char**)calloc(6, sizeof(char *)); //max 5 args + NULL pointer
  int i = 0;
  while(line) args[i++]= strsep(&line, " "); //line becomes NULL once the original string can't be parsed anymore, i++ returns starting value of i
  args[i] = NULL; //so execvp knows when to stop accepting args
  
  return args;
}

int main(){
  char command[256] = "ls -a -l -a -l";
  printf("\nExecuting %s:\n", command);
  char **args = parse_args(command);
  execvp(args[0], args);
  free(args);
  
  return 0;
}
