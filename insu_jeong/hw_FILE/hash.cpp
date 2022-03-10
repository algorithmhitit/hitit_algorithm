//h_i(x) = (x + i) % M 
//해시테이블의 크기 M은 2*N보다 크거나 같은 소수 (prime number) 중 가장 작은 숫자로 한다.
//N개의 숫자들을 개방주소 방식을 사용하는 다음의 해시 함수 h_i(x)를 이용하여 크기 M인 해시테이블에 저장한다.
//예를들어, N = 5인 경우 M = 11이 된다.

#include <stdio.h>
#include <stdlib.h>

int h_i(int x, int N);
int search_prime(int N);

int b[1000000];
int a[1000000];
int count =0;

int main() {
    int N=0;
    int ans=0;
    scanf("%d",&N);
    int M = search_prime(N*2);
    for(int i=0; i<N;i++){
        scanf("%d",&a[i]);
        b[h_i(a[i],M)] = a[i];
    }
    
    ans = count;
    printf("%d",ans);
    
    return 0;
}

//h_i(x) = (x + i) % M 
int h_i(int x,int N){
    int i=0;
    while(b[(x+i)%N] != 0){
        count++;
        x++;
    }
    return (x+i)%N;
} 

//매개변수 N보다크거나 같은 소수를 찾는다.
int search_prime(int num){
    int n = num;
    num = num*2;
    int *arr;
    arr = (int *) malloc(sizeof(int) * num);
    // 입력받은 수 만큼 배열에 모두 초기화 해둔다

    for (int i = 2; i <= num; i++) {
        arr[i] = i;
    }
    for (int i = 2; i <= num; i++) {  // 나누는 값 : i
        for (int j = 2; j <= num; j++) {
            if (arr[j] != i && arr[j] % i == 0) {  // 자신과 같지않고 0으로 떨어지면 소수아님
                arr[j] = 0; // 소수가 아닌 경우 0을 넣어둔다
            }
        }
    }

    for(int i=n;i<=n*2;i++){
        if(arr[i] != 0){
            //printf("arr[i] = %d\n",arr[i]);
            return arr[i];
        }
    }
    return -1;
}