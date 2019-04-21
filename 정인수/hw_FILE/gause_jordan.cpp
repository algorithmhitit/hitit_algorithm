//가우스 조던 방법
//방정식에 대한 상수
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EQ		20

void print_equation(float a[][MAX_EQ+1], float *b, int n)
{
	int i,j;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%8.3f",a[i][j]);
			if(j==n) printf(" = ");
			else printf(" + ");
		}
		printf("%8.3f\n", b[i]);
	}
}

int read_input(char *file,float a[][MAX_EQ+1], float *b, int *n)
{
	int i,j;
	FILE *fp;
	
	if((fp = fopen(file,"r")) == (FILE *)0) return -1;
	
	fscanf(fp,"%d", (char *)n);
	for(i=1;i<=(int)*n;i++) {
		for(j=1;j<=(int)*n;j++){
			fscanf(fp,"%f",(char *)&a[i][j]);
		}
		fscanf(fp,"%f",(char *)&b[i]);
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int i,j,k,n;
	float a[MAX_EQ+1][MAX_EQ+1], b[MAX_EQ+1], c;
	if(argc<2){
		printf("Usage: %s input-file\n", argv[0]);
	}
	if(read_input(argv[1],a,b, &n) < 0) {
		printf("cannot read the input file: &s\n",argv[0]);
		exit(-1);
	}
	
	print_equation(a,b,n);
	
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++) {
			c = a[i][k]/a[k][k];
			for(j=k;j<=n;j++){
				if((1 != k) && (j==k)) a[i][j] = 0.0;
				else if((i != k) && (j>k)) a[i][j] -= c*a[k][j];
			}
			if(i != k) b[i] -= c*b[k];
		}
		printf("\n");
		for(i=1;i<=n;i++){
			printf("x%d = %-8.3f",i,(float)b[i]/a[i][i]);
			if(i==n) printf("\n");
			else printf(",");
		}
	}
	return 0;
} 

