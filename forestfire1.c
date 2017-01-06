#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
   int row;
   int col;
   struct Node* next;
} ListNode;
int runIt(int counter, int b, int a[b][b], ListNode* c[b])
{
  int counting=0;
  while
  //make method that takes goes throug array of trees on fire(c) and takes them out one by one and make method that  
  // lights treees on sides on fire and then store in another array that it ads to then set the fire array to other array 
  //increment count and if size of array of listnodes is 0 return the steps
  
  return 5;
}
void lightSides(int b, int a[b][b], ListNode* c, ListNode* d[b], int iter)
{
  int therow=c->row;
  int thecol=c->col;
  if(a[thecol+1][therow]==1)
  {
    a[thecol+1][therow]=2;
    ListNode*temp=NULL;
    temp=(ListNode*)malloc(sizeof(ListNode));
    temp->row=therow;
    temp->col=thecol+1;
    d[iter]=temp;
    iter++;
    free(temp);

  }
  if(a[thecol][therow+1]==1)
  {
    a[thecol][therow+1]=2;
    ListNode*temp=NULL;
    temp=(ListNode*)malloc(sizeof(ListNode));
    temp->row=therow+1;
    temp->col=thecol;
    d[iter]=temp;
    iter++;
    free(temp);
  }
  if(a[thecol-1][therow]==1)
  {
    a[thecol-1][therow]=2;
    ListNode*temp=NULL;
    temp=(ListNode*)malloc(sizeof(ListNode));
    temp->row=therow;
    temp->col=thecol-1;
    d[iter]=temp;
    iter++;
    free(temp);
  }
  if(a[thecol][therow-1]==1)
  {
    a[thecol][therow-1]=2;
    ListNode*temp=NULL;
    temp=(ListNode*)malloc(sizeof(ListNode));
    temp->row=therow-1;
    temp->col=thecol;
    d[iter]=temp;
    iter++;
    free(temp);
  }
  a[thecol][therow]=0;
}
void makePlot(double p, int b, int a[b][b])
{
  int colnum;
  int rownum;
  for(colnum=0;colnum<b;colnum++)
  {
    for(rownum=0;rownum<b;rownum++)
    {
      double randnum=(double)rand()/(double)RAND_MAX;
      if(randnum<(double)p)
      {
	a[colnum][rownum]=1;
      }
      else
      {
	a[colnum][rownum]=0;
      }
    }
  }
}
void lightCol(int counter, int b, int a[b][b], ListNode* c[b]) //ARRAY OF LISTNODES c[b])
{
  int colnum=0;
  int rownum=0;
  int iter=0;
  counter++;
  for(rownum=0;rownum<b;rownum++)
  {
    if(a[colnum][rownum]==1)
    {
      a[colnum][rownum]=2;
      ListNode* temp=NULL;
      temp=(ListNode*)malloc(sizeof(ListNode));
//stores things as column, row in c
      temp->row=rownum;
      temp->col=colnum;
      c[iter]=temp;
      iter++;
      free(temp);
    }
    else
    {
    }
  }
}
int main()
{
  double prob=.75;
  int size=30;
  int steps=0;
  int plot[size][size];
  ListNode* nodes[size];
  makePlot(prob, size, plot);
  
  lightCol(steps, size, plot, nodes);
  /*int colnum;
  int rownum;
  for(colnum=0;colnum<size;colnum++)
  {
    for(rownum=0;rownum<size;rownum++)
    {
      printf("%d", plot[rownum][colnum]);
      printf("%s", " ");
    }
    printf("\n");
  }*/
  steps=runIt(steps, size, plot, nodes);
  printf("%s", "Steps:");
  printf("%d\n", steps);
 //int argc;
 // scanf("%d", &argc);
 // int plot[argc][argc];
 // printf("%d\n", argc);
 // runIt(
  return 0;
}