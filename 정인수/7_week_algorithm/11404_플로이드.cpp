#include <stdio.h>
#define INF 1000000

int main (){
    int cityNum,adjNum;
    int dist[101][101] = {0,};
    scanf("%d",&cityNum);
    scanf("%d",&adjNum);
    int from, to, val;
    
    for(int i=1;i<=cityNum;i++){
        for(int j=1;j<=cityNum;j++){
            if(i != j)
                dist[i][j] = INF;
        }
    }
    
    /*for(int i=1;i<=cityNum;i++){
        for(int j=1;j<=cityNum;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }*/

    for(int i=0;i<adjNum;i++){
        scanf("%d %d %d", &from, &to, &val);
        if(dist[from][to] > val)
            dist[from][to]=val;
    }

    

    /*for(int m=1;m<=cityNum;m++){
        for(int s=1;s<=cityNum;s++){
            for(int e=1;e<=cityNum;e++){
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }*/

    for (int m = 1; m <= cityNum; m++) //가운데 노드
		for (int s = 1; s <= cityNum; s++) //시작 노드
			for (int e = 1; e <= cityNum; e++) //마지막 노드
				if (dist[s][e] > dist[s][m] + dist[m][e])
					dist[s][e] = dist[s][m] + dist[m][e]; 

    for(int i=1;i<=cityNum;i++){
        for(int j=1;j<=cityNum;j++){
            if(dist[i][j] == INF)
                printf("0 ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}