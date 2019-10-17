#include<stdio.h>
#include<stdlib.h>
//instead of using bool, 0 = False, 1 = TRUE
int magicCheck (int** m, int size);
int colCheck (int** m, int size);
int rowCheck (int** m, int size);
int diaCheck (int** m, int size);
int dupCheck (int** m, int size, int temp);
//-------------------------------------------------
int main ( int argc, char** argv ) {
  int size;
  FILE* fefe;
  fefe = fopen(argv[1],"r");
  
  fscanf(fefe, "%d\n", &size);

  int** m = (int**) malloc(size*sizeof(int*));
  int i,j,k;
  for ( i = 0; i < size; i++) {
    m[i] = (int*) malloc(size*sizeof(int*));
  }

  for ( j = 0; j < size; j++ ) {
    for ( k = 0; k < size; k++ ) {
      fscanf(fefe, "%d\t" , &m[j][k]);
    }
    fscanf(fefe,"\n");
  }

  int x,y,temp,dcheck;
  
  for ( y = 0; y < size; y++ ) {
    temp = 0;
    for ( x = 0; x < size; x++ ) {
      temp = m[y][x];
      dcheck = dupCheck(m,size,temp); //WILL RETURN 0 IF NOT DUP NOT FOUND, 1 IF FOUND!!!!!
      if ( dcheck == 1 ) {
        printf("not-magic\n");
	return 0;
      }
    }
  }

  int cons = magicCheck(m,size);
  
  if ( cons == 1 ) {
    printf("magic\n");
  } else {
    printf("not-magic");
  }


}
//--------------------------------------------------
int magicCheck ( int** m, int size ) {
  int col = colCheck(m,size); //sending these out and they will send me -1 if they aren't
  int row = rowCheck(m,size); //equal or the total of a single col or row or diag
  int dia = diaCheck(m,size);

  if ( col == -1 || row == -1 || dia == -1 ) {
    return 0; //not magic!
  }

  if ( (col == row) && (col == dia) ) {
    return 1; //magic!
  }

  return 0;
}
//---------------------------------------------------
int rowCheck ( int** m , int size ) { //will check all the rows in m, return total if equal, -1 if not
  int cons,temp,i,j,k,p;
  cons = 0;
  for ( i = 0 ; i < 1; i++ ) { //finds total for first row, we will use this to compare with rest of m
    for ( j = 0; j < size; j++ ) {
      cons = cons + m[i][j];
    }
  }
  for ( k = 1; k < size; k++ ) {
    temp = 0;
    for ( p = 0; p < size; p++ ) {
      temp = temp + m[k][p];
    }
    if ( temp != cons ) {
      return -1;
    }
  } 
  return cons;
}
//-----------------------------------------------------
int colCheck ( int** m, int size ) { //will check all the cols in m, return total if eual, -1 if not
  int cons, temp,i,j,k,p;
  cons = 0;
  for ( i = 0; i < 1; i++ ) {
    for ( j = 0; j < size; j++ ) {
      cons = cons + m[j][i];
    }
  }
  for ( k = 1; k < size; k++ ) {
    temp = 0;
    for ( p = 0; p < size; p++ ) {
      temp = temp + m[p][k];
    }
    if ( temp != cons ) {
      return -1;
    }
  }
  return cons;
}
//------------------------------------------------------
int diaCheck ( int** m, int size) {
  int d1,d2,i,j;
  d1 = 0;
  d2 = 0;
  for ( i = 0; i < size; i++ ) {
    d1 = d1 + m[i][i];
  }
  for ( j = 0; j < size; j++ ) {
    d2 = d2 + m[size-1-j][j];
  }
  if ( d1 == d2 ) {
    return d1;
  }
  return -1;
}
//------------------------------------------------------
int dupCheck ( int** m, int size, int temp ) {
  int count = 0;
  int i,j,hold;
  for ( i = 0; i < size; i++ ) {
    hold = 0;
    for ( j = 0; j < size; j++ ) {
      hold = m[i][j];
      if ( temp == hold ) {
        count++;
      }
    }
  }
  if ( count > 1 ) {
    return 1;
  }
  return 0;
}
//-------------------------------------------------------
