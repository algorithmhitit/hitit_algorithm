#include <stdio.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main() {
    int rope_num,ans = 0,max_arr = 0;
    int arr[100000];
    int max_w = 0;
    scanf("%d",&rope_num);
    for(int i=0;i<rope_num;i++){
        scanf("%d",&arr[i]);
        max_arr += arr[i];
    }

    for(int i=0;i<rope_num;i++){
        ans = arr[i]*(i+1);
        max(ans,max_w);
    }

    printf("%d",ans);

    return 0;
}