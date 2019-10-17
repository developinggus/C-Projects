#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPrime ( int n ) {

  /* One is a prime number */
  if ( n <= 1 ) {
    return false;
  }
  int i;
  for ( i = 2; i < n; i++ ) {
    if ( n%i == 0 ) {
      return false;
    }
  }
  return true;

}

int main ( int argc , char** argv ) {

  int size;

  int ans = 1;

  FILE* fefe;
  fefe = fopen(argv[1],"r");

  fscanf(fefe,"%d\n",&size);
  /*printf("Size is %d\n", size); */

  int arr[size];


  /*size = 3;*/
  int i;

  /*int arr[3] = {333,7,1};*/

  /*int test = 395;*/

  for ( i = 0; i <  size ; i++ ) {
    fscanf(fefe,"%d\n", &arr[i]);
  }

  int j;

  for ( j = 0; j < size; j++ ) {
    int temp = arr[j];
    int temp2 = temp;
    ans = 1;
    while ( temp2 >= 1 ) {
      ans = 1;
      if ( !isPrime(temp2) ) {
        ans = 0;
        break;
      }
      /*printf("%d\n",temp2);*/
      temp2 = temp2 / 10;

    }
    if ( ans == 0 ) {
      printf("no\n");
    } else {
      printf("yes\n");
    }
  }

  
  return 0;
}

/* this is to test if the array is being read properly */
