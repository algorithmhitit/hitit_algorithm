#include <stdio.h>

int main () {
	int arr[31] = {0};
	int tmp;
	for(int i=0;i<28;i++) {
		scanf("%d",&tmp);
		arr[tmp] = 1;
	}
	
	for(int i=1;i<=30;i++){
		if(arr[i] == 0)
			printf("%d\n",i);
	}
	
	return 0;
}
