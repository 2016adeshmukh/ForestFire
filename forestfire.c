#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//make int checker to see if arra is emtpy
typedef struct Node
{
   int row;
   int col;
   struct Node* next;
} ListNode;
int lightSides(int bb, int aa[bb][bb], ListNode* cc, int ff, int hh, ListNode* y[bb])
{
  int therow=cc->row;
  int thecol=cc->col;
  printf("%d\n", therow);
  printf("%d\n", therow);
  int what=ff;
  if(thecol!=bb)
  {
  if(aa[thecol+1][therow]==1)
  {
    aa[thecol+1][therow]=2;
    ListNode* temp=NULL;
      temp=(ListNode*)malloc(sizeof(ListNode));
      temp->row=therow;
      temp->col=thecol+1;
      y[hh]=temp;
      hh++;
      free(temp);
    what++;
  }
  }
  if(therow!=bb)
  {
  if(aa[thecol][therow+1]==1)
  {
    aa[thecol][therow+1]=2;
    ListNode* temp=NULL;
      temp=(ListNode*)malloc(sizeof(ListNode));
      temp->row=therow+1;
      temp->col=thecol;
      y[hh]=temp;
      hh++;
      free(temp);
    what++;
  }
  }
  if(thecol!=0)
  {
  if(aa[thecol-1][therow]==1)
  {
    aa[thecol-1][therow]=2;
    ListNode* temp=NULL;
      temp=(ListNode*)malloc(sizeof(ListNode));
      temp->row=therow;
      temp->col=thecol-1;
      y[hh]=temp;
      hh++;
      free(temp);
    what++;
  }
  }
  if(therow!=0)
  {
  if(aa[thecol][therow-1]==1)
  {
    aa[thecol][therow-1]=2;
    ListNode* temp=NULL;
      temp=(ListNode*)malloc(sizeof(ListNode));
      temp->row=therow-1;
      temp->col=thecol;
      y[hh]=temp;
      hh++;
      free(temp);
    what++;
  }
  }
  aa[thecol][therow]=0;
  what--;
  return what;
}
int runIt(int counter, int b, int a[b][b], ListNode* c[b], int f)
{
  //make method that takes goes throug array of trees on fire(c) and takes them out one by one and make method that  
  // lights treees on sides on fire and then store in another array that it ads to then set the fire array to other array 
  //increment count and if size of array of listnodes is 0 return the steps
  int g=f;
  int counttemp=0;
  ListNode* tempfill[b];
  while(f!=0)
  {
    
    ListNode* tempnod=c[g-1];
    f=lightSides(b, a, tempnod, f, counttemp, tempfill);
    g--;
    if(g==0)
    {
      c=tempfill;
      g=f;
      counttemp=0;
      counter++;
    }
  }
  
  return counter;
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
int lightCol(int counter, int b, int a[b][b], ListNode* c[b], int f) //ARRAY OF LISTNODES c[b])
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
      f++;
    }
    else
    {
    }
  }
  return f;
}
int main()
{
  double prob=.75;
  int size=30;
  int steps=0;
  int checkings=0;
  int plot[size][size];
  ListNode* nodes[size];
  makePlot(prob, size, plot);
  
  checkings=lightCol(steps, size, plot, nodes, checkings);
 /* int colnum;
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
  steps=runIt(steps, size, plot, nodes, checkings);
  printf("%s", "Steps:");
  printf("%d\n", steps);
 //int argc;
 // scanf("%d", &argc);
 // int plot[argc][argc];
 // printf("%d\n", argc);
 // runIt(
  return 0;
}