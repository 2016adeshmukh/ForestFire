// Torbert, 16 Sept 2015
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
int n = 35;

void printForest(int f[n][n]) {
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) {
			printf("%i, ", f[i][j]);
		}
		printf("\n");
	}
}

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
	//printf("%f\n", steps);
	//printForest(f);
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
	srand( time(NULL) );

	int forest[n][n];
	
	double prob;
	double inc = .01;
	int trials = 1000;

	int i,j,t;
	for (prob=0;prob<=1;prob+=inc) {
		double avgTime = 0;
		for (t=0; t<trials; t++) {
			for (i=0;i<n;i++) {
				for (j=0;j<n;j++) {
					double chance = ((double)rand() / (double)RAND_MAX);
					if (chance < prob) {
						forest[i][j]=1;
					}
					else{
						forest[i][j]=0;
					}
				}
				if (forest[i][0]==1) {
					forest[i][0]=2;
				}
			}
			avgTime+=burn(forest,1);
		}
		avgTime/=trials;
		avgTime/=n;
		printf("%f", prob);
		printf("	");
		printf("%f\n", avgTime);
	}
	return 0 ;
}
//
// end of file
//