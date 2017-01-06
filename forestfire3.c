#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
	int row;
	int col;
}ListNode;
//runit here has to return total number of steps taken
//takes in plot, nodes, nodesSize, size for plot
//should be recursive
//ends when nodes is empty, can keep emptying secondary nodes
//and then setting nodes=to that
int lightSides(int size, int plot[size][size], ListNode* temp, ListNode* nodesB[size], int nodesBsize)
{
	int rownum=temp->row;
	int colnum=temp->col;
	if(rownum!=0)
	{
		if(plot[colnum][rownum-1]==1)
		{
			plot[colnum][rownum-1]=2;
			ListNode* temp=NULL;
			temp=(ListNode*)malloc(sizeof(ListNode));
			temp->row=rownum-1;
			temp->col=colnum;
			nodesB[nodesBsize]=temp;
			nodesBsize++;
			free(temp);
		}
	}
	if(colnum!=0)
	{
		if(plot[colnum-1][rownum]==1)
		{
			plot[colnum-1][rownum]=2;
			ListNode* temp=NULL;
			temp=(ListNode*)malloc(sizeof(ListNode));
			temp->row=rownum;
			temp->col=colnum-1;
			nodesB[nodesBsize]=temp;
			nodesBsize++;
			free(temp);
		}
	}
	if(rownum!=size-1)
	{
		if(plot[colnum][rownum+1]==1)
		{
			plot[colnum][rownum+1]=2;
			ListNode* temp=NULL;
			temp=(ListNode*)malloc(sizeof(ListNode));
			temp->row=rownum+1;
			temp->col=colnum;
			nodesB[nodesBsize]=temp;
			nodesBsize++;
			free(temp);
		}
	}
	if(colnum!=size-1)
	{
		if(plot[colnum+1][rownum]==1)
		{
			plot[colnum+1][rownum]=2;
			ListNode* temp=NULL;
			temp=(ListNode*)malloc(sizeof(ListNode));
			temp->row=rownum;
			temp->col=colnum+1;
			nodesB[nodesBsize]=temp;
			nodesBsize++;
			free(temp);
		}
	}
	else
	{

	}
	return nodesBsize;
}
int runIt(int size, int plot[size][size], ListNode* nodes[size], int nodesSize, int steps)
{
	ListNode* nodesB[size];
	int nodesBsize=0;
	while(nodesSize!=0)
	{
		int i;
		for(i=0;i<nodesSize;i++)
		{
			ListNode* temp=nodes[i];
			nodesBsize=lightSides(size, plot, temp, nodesB, nodesBsize);
		}
		nodes=nodesB;
		ListNode* nodesB[size];
		nodesSize=nodesBsize;
		nodesBsize=0;
		steps++;

	}
	return steps;
}
//make plot, takes in plot and fills it in with numbers
//plot changes itself no number changing required
void makePlot(double prob, int size, int plot[size][size])
{
	int one;
	int two;
	for(one=0;one<size;one++)
	{
		for(two=0;two<size;two++)
		{
			double randnum=(double)rand()/(double)RAND_MAX;
			if(randnum<prob)
			{
				plot[one][two]=1;
			}
			else
			{
				plot[one][two]=0;
			}
		}
	}
}
//lights first column dont need to return anything except 
//size of listnode array call that nodesSize
int lightCol(int size,int plot[size][size], ListNode* nodes[size], int nodesSize )
{
	int colnum=0;
	int rownum=0;
	for(rownum=0;rownum<size;rownum++)
	{
		if(plot[colnum][rownum]==1)
		{
			plot[colnum][rownum]=2;
			ListNode* temp=NULL;
			temp=(ListNode*)malloc(sizeof(ListNode));
			temp->row=rownum;
			temp->col=colnum;
			nodes[nodesSize]=temp;
			free(temp);
			nodesSize++;
		}
		else
		{

		}
	}
	
	return nodesSize;
}
//need to display plot sometimes
void displayIt(int size, int plot[size][size])
{
	int colnum;
    int rownum;
    for(colnum=0;colnum<size;colnum++)
    {
      for(rownum=0;rownum<size;rownum++)
      {
        printf("%d", plot[rownum][colnum]);
        printf("%s", " ");
      }
      printf("\n");
    }
}
int main()
{
	double prob=.75;
	//some prob
	int size=30;
	int steps=0;
	int nodesSize=0;
	int plot[size][size];
	ListNode* nodes[size];
	makePlot(prob, size, plot);
	//works to here
	nodesSize = lightCol(size, plot, nodes, nodesSize);
	steps++;
	//works till here
	steps=runIt(size, plot, nodes, nodesSize, steps);
	printf("%f", prob);
	printf("%s", "	");
	printf("%d\n", steps);
	return 0;
}