//배수공사
//15817번
//https://www.acmicpc.net/problem/15817
//입력 : 파이프의 종류의 수 N 합친 파이프의 길이 x
//2번째 줄부터 입력 : 파이프의 길이와 개수 ex)4 3 길이가 짧은 것부터 순서대로
//0<=Li<=x,0<Ci<=100이다. 또한 입력되는 파이프의 길이는 서로 다르다.
//----------------풀이방법 연구중-----------------
//출력 : 합친 파이프의 길이 x를 만들수 있는 방법의 수
//tmp와 cmb라는 배열을 만들었다.
//cmb는 예를 들면 cmb[100]이면 x가 100일때의 방법의 수를 저장해둔 배열이다.
//tmp는 cmb를 값을 저장해 주기 위해 임시로 만든 배열이다.
//cmb라는 각 자리수의 방법의 수를 저장해줘서 bynamic프로그래밍 방식으로 풀었다.

#include <stdio.h>
using namespace std;

//파이프 구조체, 파이프의 종류와 그 개수를 입력받는다.
struct pipe {
    int pl;//pipeLenght의 약자, 파이프의 길이를 나타냄
    int pn;//pipeNum의 약자, 파이프의 개수를 나타냄
};

int pipeMethod(int kindNum, int x, pipe p[]);
void plusTmp(int tmp[], int cmb[], int x);

int main() {
    int kindNum;//파이프의 종류
    int x;//합친 파이프의 길이
    pipe p[1000];//파이프의 길이와 개수를 입력받음
    int ans;

    scanf("%d %d",&kindNum,&x);
    for(int i=0 ; i<kindNum ; i++){
        scanf("%d %d", &p[i].pl, &p[i].pn);
    }

    ans = pipeMethod(kindNum,x,p);

    printf("ans : %d",ans);

    return 0;
}

//파이프 메소드는 x길이의 방법의 개수를 구하는 함수이다.
int pipeMethod(int kindNum, int x, pipe p[]){
    int cmb[20001] = {0,};
    int tmp[20001] = {0,};
    //첫번째 for문에서는 파이프의 종류만큼 for문을 돌려주고 i는 파이프의 종류를 나타낸다.
    for(int i=0;i<kindNum;i++){
        for(int j=0;j<=x;j++){
            //tmp배열을 x범위만큼 0으로 초기화 시켜 주었다.
            tmp[j] = 0;
        }
        printf("i = %d(kindNum)\n", i);
        for(int j=0;j<=x;j++){
            //tmp에 값을 주기위해 x번만큼 for문을 돌려주었다.
            printf("j = %d\n",j);
            for(int k=1;k<=p[i].pn;k++){
                //파이프의 개수만큼 for문을 돌려준다.
                //및에 if문은 런타임 에러를 방지, 배열이 범위를 벗어난곳을 참조하는것을 막아준다.
                if((j+(p[i].pl)*k)<=x){
                    //tmp[j+(p[i].pl)*k]에 j일때 방법의 수를 추가로 더해준다.
                    tmp[j+(p[i].pl)*k] = tmp[j+(p[i].pl)*k] + cmb[j];
                }
                printf("tmp[%d] : %d\n", j+(p[i].pl)*k,tmp[j+(p[i].pl)*k]);
            }
        }

        //1가지 종류만 사용한 파이프의 조합에 +1을 해준다.
        for(int j=1; j<=p[i].pn; j++){
            if((p[i].pl)*j <= x){
                tmp[(p[i].pl)*j]++;
            }
            printf("tmp[%d]++\n",p[i].pl*j);
        }

        //tmp에 있던 임시 값들을 cmb 배열로 옮겨주는 함수이다.
        plusTmp(tmp,cmb,x);

        for(int i=0;i<=x;i++){
        printf("cmb[%d] = %d\n",i,cmb[i]);
        }
    }

    for(int i=0;i<=x;i++){
        printf("cmb[%d] = %d\n",i,cmb[i]);
    }

    return cmb[x];
}

//tmp에 있던 임시 값들을 cmb 배열로 옮겨주는 함수이다.
void plusTmp(int tmp[], int cmb[], int x){
    for(int i=1;i<=x;i++){
        cmb[i] = cmb[i] + tmp[i];
    }
}