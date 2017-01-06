#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

typedef struct Node
{
    int row;
    int col;
}ListNode;

double gettime()
{
    double t ;
    //
    struct timeval* ptr = (struct timeval*)malloc( sizeof(struct timeval) ) ;
    //
    gettimeofday( ptr , NULL ) ; // second argument is time zone... NULL
    //
    t = ptr->tv_sec * 1000000.0 + ptr->tv_usec ;
    //
    free( ptr ) ;
    //
    return t / 1000000.0 ;
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
            double randnum=(double)rand()/RAND_MAX;
            if(randnum<=prob)
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
int lightCol(int size,int plot[size][size], int rowfire[size], int colfire[size], int nodesSize )
{
    int colnum=0;
    int rownum=0;
    for(rownum=0;rownum<size;rownum++)
    {
        if(plot[colnum][rownum]==1)
        {
            plot[colnum][rownum]=2;
            rowfire[nodesSize]=rownum;
            colfire[nodesSize]=colnum;  
            //free(temp);
            nodesSize++;
        }
        else
        {

        }
    }
    
    return nodesSize;
}
//runit here has to return total number of steps taken
//takes in plot, nodes, nodesSize, size for plot
//should be recursive
//ends when nodes is empty, can keep emptying secondary nodes
//and then setting nodes=to that
int lightSides(int size, int plot[size][size], int rowA, int colA, int rowBfire[size*size], int colBfire[size*size], int nodesBsize)
{
    int rownum=rowA;
    int colnum=colA;
    if(rownum!=0)
    {
        if(plot[colnum][rownum-1]==1)
        {
            plot[colnum][rownum-1]=2;
            rowBfire[nodesBsize]=rownum-1;
            colBfire[nodesBsize]=colnum;
            nodesBsize++;
        }
    }
    if(colnum!=0)
    {
        if(plot[colnum-1][rownum]==1)
        {
            plot[colnum-1][rownum]=2;
            rowBfire[nodesBsize]=rownum;
            colBfire[nodesBsize]=colnum-1;
            nodesBsize++;
        }
    }
    if(rownum!=size-1)
    {
        if(plot[colnum][rownum+1]==1)
        {
            plot[colnum][rownum+1]=2;
            rowBfire[nodesBsize]=rownum+1;
            colBfire[nodesBsize]=colnum;
            nodesBsize++;
        }
    }
    if(colnum!=size-1)
    {
        if(plot[colnum+1][rownum]==1)
        {
            plot[colnum+1][rownum]=2;
            rowBfire[nodesBsize]=rownum;
            colBfire[nodesBsize]=colnum+1;
            nodesBsize++;
        }
    }
    plot[colnum][rownum]=0;
    return nodesBsize;
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
int runIt(int size, int plot[size][size], int rowfire[size*size], int colfire[size*size], int nodesSize, int steps)
{
    int rowBfire[size*size];
    int colBfire[size*size];
    int nodesBsize=0;
    double tic;
    while(nodesSize!=0)
    {
        int i;
        for(i=0;i<nodesSize;i++)
        {
            int rowA=rowfire[i];
            int colA=colfire[i];
            nodesBsize=lightSides(size, plot, rowA, colA, rowBfire, colBfire, nodesBsize);
        }
        rowfire=rowBfire;
        colfire=colBfire;
        int rowBfire[size*size];
        int colBfire[size*size];
        nodesSize=nodesBsize;
        nodesBsize=0;
//        displayIt(size, plot);
//        tic = gettime();
//        while (gettime() - tic < 0.75)
//            continue;
//        system("clear");
        steps++;

    }
    return steps;
}



int main()
{
    double prob=.0;
    while(prob<=1.00)
    {
    int x;
    int tot=0;
    double avg=0;
    for(x=0;x<1000;x++)
    {
       int size=30;
    int steps=0;
    int nodesSize=0;
    int rowfire[size*size];
    int colfire[size*size];
    int plot[size][size];

    makePlot(prob, size, plot);
    //works to here
    nodesSize = lightCol(size, plot, rowfire, colfire, nodesSize);
    steps++;
    //works till here
    steps=runIt(size, plot, rowfire, colfire, nodesSize, steps); 
    tot=tot+steps;
    }
    avg=(double)tot/1000;
    
    printf("%f", prob);
//    printf("%s", "  ");
//    printf("%d\n", steps);
    printf("%f\n", avg/30);
    prob=prob+.01;
}
    return 0;
}







