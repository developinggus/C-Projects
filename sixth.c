#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//--------------------------------------------------
//int isVowl (char* letter);
//--------------------------------------------------
int main ( int argc, char** argv ) {
  /*
  char* str;
  //char* letter;
  int i;
  int size;
  //char* new;
  for ( i = 1; i < argc; i++ ) {
    str = argv[i];
    size = strlen(str);
  }
  int j;
  for ( j = 0 ; j < size; j++) {
    printf("%c", str[j]);
  }
  return 0;
  */
  
  int i,j,k,p;
  char* str;
  int size;
  //char* letter;
  int check = 0;
  //int print;
  for ( i = 1; i < argc; i++ ) {
    //printf("%d\n",argc);
    check = 0;
    str = argv[i];
    //printf(str);
    //printf("\n");
    //letter = str[0];
    //check = isVowl(letter); //return 1 if a vowel, return 0 if not;
    if ( str[0] == 'a'|| str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'A'|| str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U') {
      check = 1;   
    }
    if ( check == 1 ) { //is a vowel
      printf(str);
      printf("yay ");
    } else { //must be a constant
      size = strlen(str);
      //printf(str);
      //printf(" does not start with a vowel");
      //printf("\n");
      for ( j = 0; j < size; j++ ) {
        if ( str[j] == 'a'|| str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[0] == 'A'|| str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U') {
          for ( k = j; k < size; k++ ) {
            printf("%c", str[k]);
          }
          for ( p = 0; p < j; p++ ) {
            printf("%c", str[p]);
          }
          printf("ay ");
          size = -1;
       }
      }
    }
  }
  return 0;
}
/*/---------------------------------------------------------------
int isVowl(char* letter) {
  if ( letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ) {
    return 1;
  }
  return 0;
}
*///---------------------------------------------------------------
