
#include <stdio.h>
#include <algorithm>

using namespace std;

int main (){
	int n;//ī���� ���� 
	scanf("%d",&n);
	int max = 0;//�ִ밪 
	int arr[10000]={0,};
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	stable_sort(arr,arr+n);
	
	int arr_end = n-1;
	
	//+++
	if(max < arr[arr_end]*arr[arr_end-1]*arr[arr_end-2]){
		max = arr[arr_end]*arr[arr_end-1]*arr[arr_end-2];
	}
	//++
	if(max < arr[arr_end]*arr[arr_end-1]){
		max = arr[arr_end]*arr[arr_end-1];
	}
	//--
	if(max < arr[0]*arr[1]){
		max = arr[0]*arr[1];
	}
	//+--
	if(max < arr[arr_end]*arr[0]*arr[1]){
		max = arr[arr_end]*arr[0]*arr[1];
	}
	
	printf("%d",max);
	
	return 0;
}
