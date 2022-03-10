//정수삼각형
//1932번
//https://www.acmicpc.net/problem/1932

#include <stdio.h>
int a[1000000];
int v[1000000];
int main () {
    int size = 0;
    int count = 0;
    scanf("%d", &size);
    int num = (size*(size+1))/2;
    for(int i=0;i<num;i++){
        scanf("%d", &v[i]);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<=i;j++){
            a[count] = i;
            count++;
        }
    }
    int left;
    int right;
    int bigger;
    int max = 0;
    for(int i=0;i<num;i++){
        if(i==0){

        }
        else if(i==1){
            v[i] += v[0];
        }
        else if(i==2){
            v[i] += v[0];
        }
        else{
            left = i-a[i]-1;
            right = i-a[i];
            if(a[left] == a[right]){
                if(v[left] > v[right]) {
                    bigger = v[left];
                }
                else{
                    bigger = v[right];
                }
            }
            else if(a[left] < a[right] && a[right] == a[i]-1){
                bigger = v[right];
            }
            else if(a[left] < a[right] && a[right] == a[i]){
                bigger = v[left];
            }
            v[i] = v[i] + bigger;
        }
        if(max < v[i]){
            max = v[i];
        }
    }
    
    printf("%d",max);
}