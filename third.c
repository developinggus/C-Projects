#include<stdio.h>
#include<stdlib.h>
//-----------------------------------------------------------------------------
typedef struct node {
  int data;
  struct node * next;
}node;
//-----------------------------------------------------------------------------
typedef struct buckets{
  struct node** row;
}buckets;
//-----------------------------------------------------------------------------
buckets * insert ( buckets * hashtable, int num);
int search ( buckets * hashtable, int num);
//-----------------------------------------------------------------------------
int main ( int argc , char** argv ) {
  //creating the hashtable
  buckets* hashtable = (buckets*) malloc(sizeof(buckets)); //create the array of buckets
  hashtable->row = malloc(1000*sizeof(node*));
  int i,num,s;
  char op;
  for ( i = 0; i < 1000; i++ ) {
    hashtable->row[i] = NULL;
  }
  //printf("Line 27\n");
  FILE* fefe;

  fefe = fopen(argv[1], "r");

  if ( fefe == NULL ) {
    printf("error\n");
  }

  while ( fscanf(fefe,"%c\t%d\n", &op, &num) != EOF ) {
    if ( op == 'i' ) { //insert
      //printf("OP is : %c\n",op);
      s = search(hashtable,num); //return 1 if found
      //printf("Line 39\n");
      if ( s == 1 ) {
        printf("duplicate\n");
      } else {
        //printf("About to fire insert\n");
	hashtable = insert(hashtable,num);
        //printf("Line 44\n");
	printf("inserted\n");
      }
    } else { //must be search
      s = search(hashtable,num);
      if ( s == 1 ) { //found
        printf("present\n");
      } else {
        printf("absent\n");
      }
    }
  }
  return 0;
}
//-----------------------------------------------------------------------------
buckets * insert ( buckets * hashtable, int num ) {
  node* temp = (node*) malloc(sizeof(node)); //create a new node
  //printf("Line 61\n");
  temp->data = num;
  //temp->next = NULL;
  //printf("Line 66\n");
  int key;
  int size = 1000;
  //printf("Line 68\n"); 
  key = num % size;
  if ( key < 0 ) {
    key = key * -1;
  }
  //printf("Insert key is : %d\n",num);
  //printf("Line 71\n");
  if (hashtable->row[key] == NULL ) { //nothing has been entered yet
    //printf("Key is Null! Entering %d\n",num);
    hashtable->row[key] = temp; //adding the new num
    return hashtable;
  }

  node * p = NULL;

  p = hashtable->row[key]; //takes us the the bucket

  while ( p->next != NULL ) {
    p = p->next;
  }
  //printf("Traversed Linked List! Adding %d\n",num);
  p->next = temp;
  return hashtable;
}
//-----------------------------------------------------------------------------
int search ( buckets* hashtable , int num ) { //searches for num , return one if found!
  int key,temp;
  node* hold = NULL;
  int size = 1000;
  node* p = NULL;
  key = num % size;
  if ( key < 0 ) {
    key = key * -1;
  }
  //printf("Search key is : %d\n",key);
  if ( hashtable->row[key] == NULL ) {
    return 0; // not found
  }

  hold = hashtable->row[key];
  temp = hold->data;
  p = hashtable->row[key];

  if ( temp == num ) { //found in the first linked list
    return 1; //found!
  }
  
  while ( p != NULL ) {
    temp = p->data;
    if ( temp == num ) {
      return 1;
    }
    p = p->next;
  }
  return 0;
}
//-----------------------------------------------------------------------------  
