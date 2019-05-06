//천재 수학자 성필
//15815
//https://www.acmicpc.net/problem/15815
#include <stdio.h>

struct tree {
    char data;
    int type;//type :1 이면 숫자, type:2+,3-,4/,5*
};

int seperate(tree a[],int tmp){
    int nCount=0,opCount=0;
    while(nCount<=opCount){
        if(a[tmp].type == 1){
            nCount++;
        }
        else{
            opCount++;
        }
        tmp--;
    }
    return tmp;
}

int cal(tree a[],int size){
    int tmp=size-1;
    //printf("a[%d].data = %d\n",size,a[size].data);
    if(a[size].type == 1){
        //printf("(int)a[%d].data = %d\n",size,a[size].data-48);
        return a[size].data-48;
    }
    else if(a[size].type == 2){
        if(a[size-2].type == 1 && a[size-1].type == 1)
            return cal(a,size-2)+cal(a,size-1);
        else{
            tmp = seperate(a,tmp);
            return cal(a,tmp)+cal(a,size-1);
        }
    }
    else if(a[size].type == 3){
        if(a[size-2].type == 1 && a[size-1].type == 1)
            return cal(a,size-2)-cal(a,size-1);
        else{
            tmp = seperate(a,tmp);
            return cal(a,tmp)-cal(a,size-1);
        }
    }
    else if(a[size].type == 4){
        if(a[size-2].type == 1 && a[size-1].type == 1)
            return cal(a,size-2)/cal(a,size-1);
        else{
            tmp = seperate(a,tmp);
            return cal(a,tmp)/cal(a,size-1);
        }
    }
    else if(a[size].type == 5){
        if(a[size-2].type == 1 && a[size-1].type == 1)
            return cal(a,size-2)*cal(a,size-1);
        else{
            tmp = seperate(a,tmp);
            return cal(a,tmp)*cal(a,size-1);
        }
    }
}

int main() {
    tree a[200];
    int size = 0;
    char tmp[201];
    scanf("%200s",tmp);
    fflush(stdin);

    int i=0;
    while(tmp[i] != NULL){
        a[i].data = tmp[i];
        if(tmp[i] >= 48 && tmp[i] <=57){
            a[i].type = 1;
        }
        else if(tmp[i] == '+'){
            a[i].type = 2;
        }
        else if(tmp[i] == '-'){
            a[i].type = 3;
        }
        else if(tmp[i] == '/'){
            a[i].type = 4;
        }
        else if(tmp[i] == '*'){
            a[i].type = 5;
        }
        //printf("tmp[%d] = %c\n",i,tmp[i]);
        i++;
        size = i;
    }

    int ans = cal(a,size-1);

    printf("%d",ans);

    return 0;
}