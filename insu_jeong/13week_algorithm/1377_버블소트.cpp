#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct arr {
	int val;
	int index;
};

bool compare(arr a, arr b){
	return a.val < b.val;
}

arr a[500001] = {0,};
int main(){
	int n;
	//int a[500001]={0,};
	int max = 0;
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].index = i;
	}
	
	stable_sort(a+1,a+n+1,compare);
	
	for(int i=1;i<=n;i++){
		if(max < a[i].index-i){
			max = a[i].index-i;
		}
		printf("max = %d ,compare = %d \n",max,a[i].index-i);
	}
	
	printf("%d",max+1);
	/*
	bool change = false;
	for (int i=1; i<=n+1; i++) {
	    change = false;
	    
	    for(int j=1;j<=n;j++){
	    	printf("%d ",a[j]);	
		}
		printf("\n");
	    
		for (int j=1; j<=n-i; j++) {
			
	        if (a[j] > a[j+1]) {
	            change = true;
	            swap(a[j], a[j+1]);
	        }
	    }
	    
	    if (change == false) {
	        cout << i << '\n';
	        break;
	    }
	}*/
	
	return 0;
}


