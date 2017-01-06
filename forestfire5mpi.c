// Torbert, 16 Sept 2015
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
#include "mpi.h"
int n = 30;


int check(int f[n][n]) {
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) {
			if (f[i][j]!=0 && f[i][j]!=1) {
				return 0;
			}
		}
	}
	return 1;
}


double burn(int f[n][n], double steps) {
	if (check(f)==1) {
		return steps;
	}
	else {
		int i,j;
		for (i=0;i<n;i++){
			for (j=0;j<n;j++) {
				if (f[i][j]==steps+1) {
					if (i>0 && f[i-1][j]==1) {
						f[i-1][j]=steps+2;
					}
					if (i<n && f[i+1][j]==1) {
						f[i+1][j]=steps+2;
					}
					if (j>0 && f[i][j-1]==1) {
						f[i][j-1]=steps+2;
					}
					if (j<n && f[i][j+1]==1) {
						f[i][j+1]=steps+2;
					}
					f[i][j]=0;
				}
			}
		}
		steps+=1;
		return burn(f,steps);	
	}
}

int main( int argc , char* argv[] )
{
	srand( time(NULL) )			;
	int forest[n][n]			;
	int        rank         		;
	int        size         		;
	MPI_Status status       		;
	int        tag    = 0   		;
	double     prob         		;
	double     inc    = .01 		;
	int        trials = 1000		;
	double 	   totavg			;	
	double 	   avgTime			;
	double 	   result			;
        MPI_Init(      &argc          , &argv ) ;
	MPI_Comm_size( MPI_COMM_WORLD , &size ) ; // same
	MPI_Comm_rank( MPI_COMM_WORLD , &rank ) ; // different
	int i,j,t,k				;
	
	if (rank==0)
	{
		prob=0;
		while(prob<=1)
	  	{
	    	totavg=0;
	    	for( j=0;j<size;j++)
	    	{
	    	  MPI_Send( &prob , 1 , MPI_DOUBLE , j , tag , MPI_COMM_WORLD ) ;
	    	  MPI_Recv(&avgTime,1,MPI_DOUBLE, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
	    	  printf("%f : %f\n", prob, avgTime);
	    	  prob+=inc;
	    	}
	  	}
	}
	else
	{
		prob=0;
		while(prob<=1)
		{
			for(k=0;k<size;k++)
			{
				MPI_Recv(&prob, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
				double avgTime=0;
				for(t=0;t<trials;t++)
				{
					for(i=0;i<n;i++)
					{
						for(j=0;j<n;j++)
						{
							double chance=((double)rand()/(double)RAND_MAX);
							if(chance<prob)
							{
								forestfire[i][j]=1;
							}
							else
							{
								forestfire[i][j]=0;
							}
						}
						if(forestfire[i][0]==1)
						{
							forestfore[i][0]=2;
						}
					}
					avgTime+=burn(forest,1);
				}
				avgTime/=trials;
				avgTime/=n;
				MPI_Send(&avgTime, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);printf("%f : %f\n", prob, avgTime);
				prob+=inc;
			}
		}
	}
	MPI_FINALIZE() ;
	return 0 ;
}
//
// end of file
//