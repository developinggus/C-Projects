#include<stdio.h>
#include<stdlib.h>

int * getRow (int row, int**m1,int m1col,int rowSize);
int * getCol (int col, int**m2,int m2row, int colSize);
int mult(int * row, int * col, int n);
int insert (int temp, int**nm, int row, int col);
//-------------------------------------------------------------------------------
int main ( int argc , char ** argv ) {
  int R1; // rows and collumns of the first matrix
  int C1;
  int R2;
  int C2;
  FILE *fefe;
  fefe = fopen(argv[1],"r");
  fscanf(fefe, "%d\t%d\t\n" , &R1 , &C1);
  //printf("I made it\n");
  //Now we know how big the first array should be
  int i;
  int ** m1;
  m1 = (int**) malloc(R1 * sizeof(int *)); // creating the first array of int pointers and  
  for ( i = 0; i < R1; i++ ) {//allocating space for the matrix
    m1[i] = (int*) malloc(C1*sizeof(int));
  }
  //printf("I made it\n");
  int y1;
  int x1;
  for (y1 = 0; y1 < R1; y1++ ) {//inserting the elements into the matrix
    for ( x1 = 0; x1 < C1; x1++ ) {
      fscanf(fefe, "%d", &m1[y1][x1]);
    }
  }
  //printf("I made it\n");
  fscanf(fefe, "%d\t%d\t\n" , &R2 , &C2 );
  int ** m2;
  m2 = (int**) malloc(R2 * sizeof(int *));
  int j;
  for ( j = 0; j < R2; j++ ) {
    m2[j] = (int*) malloc(C2*sizeof(int));
  }
  //printf("I made it 41\n");
  int y2;
  int x2;
  for ( y2 = 0; y2 < R2; y2++ ) {
    for ( x2 = 0; x2 < C2; x2++ ) {
      //printf("I made it\n");
      fscanf(fefe, "%d", &m2[y2][x2]);
    }
  }
  //printf("I made it\n");
  if ( C1 != R2 ) { //the # of col. of the first matrix MUST be equal to the # of rows of the 2nd matrix
    printf("bad-matrices\n");
    return 0;
  }
  //printf("I made it\n");
  int * tempRow = malloc(sizeof(int));
  int * tempCol = malloc(sizeof(int));
  //printf("I made it 58\n");
  int **nm;
  nm = (int**) malloc(R1 * sizeof(int *));
  int z;
  for ( z = 0; z < R1; z++ ) {
    nm[z] = (int*) malloc(C2* sizeof(int));
  }
  int x,y;
  for ( x = 0 ; x < R1; x++ ) {
    for ( y = 0; y < C2; y++ ) {
      //printf("I made it\n");
      nm[x][y] = -1;
    }
  }
  //printf("I made it 72\n");
  int ti, tj, temp;

  for ( ti = 0; ti < R1; ti++ ) {
    //printf("Line 78\n");
    tempRow = getRow(ti,m1,C1,C1);
    for ( tj = 0; tj < C2; tj++ ) {
      //printf("Line 79\n");
      tempCol = getCol(tj,m2,R2,R2);
      //printf("Line 81 \n");
      temp = mult(tempRow,tempCol,R2);
      //printf("Line 83\n");
      insert(temp,nm,R1,C2);
    }
  }
  //printf("I made it 83\n");
  int g,b;
  for ( g = 0; g < R1; g++ ) {
    for ( b = 0; b < C2; b++ ) {
      printf("%d\t",nm[g][b]);
    }
    printf("\n");
  } 
}
//--------------------------------------------------------------------
int * getRow(int row, int ** m1, int m1col, int rowSize) {
  int * tempArr = malloc(rowSize *sizeof(int));
  int i;
  for ( i = 0; i < m1col; i++ ) {
    tempArr[i] = m1[row][i];
    //printf("%d\t", tempArr[i]);
  }
  return tempArr;
}
//--------------------------------------------------------------------
int * getCol(int col, int ** m2, int m2row, int colSize) {
  int * tempArr = malloc(colSize *sizeof(int));
  int i;
  for ( i = 0; i < m2row; i++ ) {
    tempArr[i] = m2[i][col];
  }
  return tempArr;
}
//---------------------------------------------------------------------
int mult ( int * row, int * col , int n ) {
  
  int temp = 0;
  int mtemp = 0;
  int i;
  for ( i = 0; i < n ; i++ ) {
    mtemp = row[i] * col[i];
    temp = temp + mtemp;
  }
  return temp;
}
//--------------------------------------------------------------------
int insert ( int temp, int** nm, int row, int col ) {
  int i,j,hold;
  for ( i = 0; i < row; i++ ) {
    for ( j = 0; j < col; j++ ) {
      hold = nm[i][j];
      if ( hold == -1 ) {
        nm[i][j] = temp;
        return 0;
      }
    }
  }
  return 0;
}
//--------------------------------------------------------------------
