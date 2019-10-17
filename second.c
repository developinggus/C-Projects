#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//-------------------------------------
typedef struct node {
  int data;
  struct node * next;
} node;
//-------------------------------------
node * newLinked (node * head, int n);
node * sort ( node * head );
node * deleter ( node * head , int n);
bool sortedChecker ( node * head );
int linkedCounter ( node * head );
int bringMeSmallest ( node * head );
int numExist(node * head, int num);
int isMatch( node * head, int num);
void free_list();
//-------------------------------------
int linkedCounter ( node * head ) {
  struct node * p = head;
  int count = 0;
  while ( p != NULL) {
    count = count + 1;
    p = p->next;
  }
  return count;
}
//-------------------------------------
int bringMeSmallest ( node * head ) {

  int smallest = head->data;
  struct node * p = head;
  while ( p != NULL ) {
    if ( p->data < smallest ) {
      smallest = p->data;
    }
    p = p->next;
  }
  return smallest;
}
//-------------------------------------
bool sortedChecker ( node * head ) {
  int num;
  int nextNum;
  struct node * p = head;
  struct node * temp = NULL;
  if ( p->next == NULL ) { //single element, ofcourse it true
    return true;
  }
  while ( p->next != NULL ) {
    num = p->data;
    temp = p->next;
    nextNum = temp->data;
    if ( num > nextNum ) {
      return false;
    }
    p = p->next;
  }
  return true;
}
//------------------------------------
node * sort ( node * head ) {
  //printf("I made it to sort\n");
  struct node * pnewLL = NULL;
  struct node * newLL = malloc(sizeof(node));
  /*struct node * p = head;*/
  int smallest;
  if ( sortedChecker(head) ) {
    //printf("All good 62\n");
    return head;
  }
  while ( head != NULL ) { //checks to see if linked list is sorted
    smallest = bringMeSmallest(head);
    //printf("Bring me smallest : %d\n",smallest);
    if ( newLL == NULL ) {
      newLL->data = smallest;
      newLL->next = NULL;

    } else {
      pnewLL = newLL;
      while ( pnewLL->next != NULL) {
        pnewLL = pnewLL->next;
      }
      struct node * temp = malloc(sizeof(node));
      temp->data = smallest;
      temp->next = NULL;
      pnewLL->next = temp;
    }
    head = deleter(head,smallest);
  }
  newLL = newLL->next;
  return newLL;

}
//-------------------------------------
int isMatch ( node * head, int num ) { /* checks for match in linked list before adding */

  if ( head == NULL ) {
    return 0;
  }
  struct node * p = head;
  //int a = n;
  int temp;
  while ( p != NULL ) {
    temp = p->data;
    if ( temp == num ) {
      return 1;
    }
    p = p->next;
  }
  return 0;
}
//----------------------------------
int main ( int srgc , char** argv ) {

  node * head = NULL;

  /*struct node * p = NULL; */
  char op;
  int num,check;

  FILE * fefe;
  fefe = fopen(argv[1],"r");
  //node * o = NULL;
  if ( fefe == NULL ) {
    printf("error\n");
    return 0;
  }
  //printf("Line 120\n");
  while (fscanf(fefe,"%c\t%d\n",&op,&num) != EOF ) {
    //printf("Currenty Holding : %d\n", num);
    if (op == 'i') { /* we can add */
      if ( isMatch(head,num) == 1 ) {

      } else {
	//printf("I inserted %d\n",num);
        head = newLinked(head,num);
      }

    } else if (op == 'd'){
      check = numExist(head,num);
      //printf("I deleted %d",num);
      if ( check  == 1 ){ //if the number exist, it will return one
        head = deleter(head,num);
	//printf("I deleted %d\n",num);
      } else {
        //printf("%d doesn't exist\n", num);
      }
      //head = deleter(head,num);
    }
    /*
    o = head;
    while ( o != NULL ) {
      printf("%d\t", o->data);
      o = o->next;
    }
    */
    
  }
  /*//delete this one after
  node * g = head;
  while ( g != NULL ) {
    printf("%d\t", g->data);
    g = g->next;
  }
  */
  int count = linkedCounter(head);
  if ( count == 0 ) {
    printf("%d\n",count);
    return(0);
  }
  head = sort(head);
  node * p = head;
  /*//printf("I sorted\n");
  int count = linkedCounter(head);
  if ( count == 0 ) {
    printf("%d\n", count); //nothing to print out, might aswell return
    return(0);
  }
  */
  printf("%d\n", count);

  while ( p != NULL ) {
    printf("%d\t", p->data);
    p = p->next;
  }

  //free_list();
  return 0;
}
//-------------------------------------
node * newLinked (node * head, int n ) {
  node * temp = NULL;
  int tempvar;
  temp = (node*)malloc(sizeof(node));
  tempvar = n;
  temp->data = tempvar;
  temp->next = head;

  return temp;
}
//--------------------------------------
node * deleter ( node * head, int n ) {

  if ( head == NULL ) {
    return head;
  }

  if ( head->data == n ) {
    head = head->next;
    return head;
  }
  node * prev = head;
  node * p = head->next;
  while ( p != NULL ) {
    if ( p->data == n ) {
      prev->next = p->next;
    }
    prev = p;
    p = p->next;
  }
  return head;
}
/*---------------------------------------
void free_list() {
  node * temp = head;
  while ( temp != NULL ) {
    node * temp2 = temp;
    temp = temp->next;
    free(temp2);
  }
}

*///---------------------------------------
int numExist ( node * head, int num ) {
  node * p = head;
  //int count = 0;
  int temp;
  while ( p != NULL ) {
    temp = p->data;
    if ( temp == num ) {
      return 1;
    }
    p = p->next;
  }
  return 0;
}
//----------------------------------------
