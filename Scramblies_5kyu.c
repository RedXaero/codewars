#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool scramble( char *str1,  char *str2);

int main() {

    printf((scramble("rkqdolw", "world")) ? "true" : "false");
    return 0;
}



bool scramble( char *str1,  char *str2)
{
  int sizeStr1 = strlen (str1);
  int sizeStr2 = strlen (str2);
  int i, j;
  char s1 [sizeStr1 + 1];
  char s2 [sizeStr2 + 1];
  char espacio = ' ';

  for(i = 0; i < sizeStr1; i++){
      s1[i] = str1[i];
  }
  for(i = 0; i < sizeStr2; i++){

        s2[i] = str2[i];
  }

  if(sizeStr1 < sizeStr2)
    return false;
  else if(sizeStr1 >= sizeStr2){
    for(i = 0; i < sizeStr1; i++){
      for(j = 0; j < sizeStr2; j++){
        if(s1[i] == s2[j]){
            s1[i] = espacio;
            s2[i] = espacio;
          break;
        }
      }
    }

    for(i = 0; i < sizeStr2; i++){
      if(s2[i] != espacio){
        return false;
      }
    }
  }
  return true;
}