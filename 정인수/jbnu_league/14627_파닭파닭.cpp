//파닭파닭
//14627번
//https://www.acmicpc.net/problem/14627
#include <stdio.h>

int dak[1000000];

int findmin(int dak[],int paNum){
    int min=dak[0];
    for(int i=1;i<paNum;i++){
        if(min > dak[i]){
            min = dak[i];
        }
    }
    return min;
}

int main() {
    int paNum;
    int padakNum;
    int min;
    int num = 0,ans = 0;
    scanf("%d %d",&paNum,&padakNum);
    for(int i=0;i<paNum;i++){
        scanf("%d",&dak[i]);
    }
    min = findmin(dak,paNum);
    int left =0,right = min;
    int middle=0;
    //파는 1개 이상 넣으면 안된다.
    while(left < right){
        middle =(left+right)/2;
		//printf("left : %d right : %d\n",left,right);
        num = ans = 0;
        for(int i=0;i<paNum;i++){
        	num =num + dak[i]/middle;
    	}
        if(num<padakNum){
            right = middle-1;
        }
        else{
            left = middle;
    	}
    }

    for(int i=0;i<paNum;i++){
        ans = ans + dak[i]-left*(dak[i]/left);
    }

    //printf("left = %d , ans = %d",left,ans);
    printf("%d",ans);
    return 0;
}