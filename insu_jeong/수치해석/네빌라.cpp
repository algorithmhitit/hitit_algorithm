#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PTS 10

float calc_product(float,float,float,float,float);

int read_input(char *file, float x[], float y[], int *n)
{
    int i;
    FILE *fp;

    if((fp = fopen(file, "r")) == (FILE *)0) return -1;

    fscanf(fp, "%d", (char *)n);
    for(i=0;i< (int)*n;i++)
        fscanf(fp,"%f%f", (char *)&x[i], (char *)&y[i]);

    return 1;
} 

main (int argc, char *argv[])
{
    int i,j,k,n;
    float xi[MAX_PTS], yi[MAX_PTS], x, y;
    float gp[MAX_PTS], gc[MAX_PTS];

    if(argc<3) {
        printf("Usage: %s input-file x\n", argv[0]);
        exit(0);
    }

    if(read_input(argv[1],xi,yi,&n) < 0){
        printf("cannot read the inputfile: %s\n",argv[1]);
        exit(-1);
    }

    x=(float)atof(argv[2]);

    printf("=(xi,yi): input ==========================\n");
    for(i=0;i<n;i++)
        printf("(%.5f, %.5f)\n", xi[i],yi[i]);
    printf("==========================================\n");

    for(i=0;i<n;i++){
        gc[0] = yi[i];
        for(j=1,k=1;j>=1;j--,k++){
            y = calc_product(gp[i-j], gc[i-j], xi[i], xi[i-k],x);
            gc[i-j+1] = y;
        }
        for(j=0;j<=i;j++)
            gp[j] = gc[j];
    }

    printf("(x, g(x), sqrt(x)) = (%.6f, %.6f, %.6f)\n", x, y, sqrt((float)x));
}

float calc_product(float gp, float gc, float xe, float xs, float x)
{
    return ( ((x-xs)*gc - (x-xe)*gp) / (xe-xs) );
}

