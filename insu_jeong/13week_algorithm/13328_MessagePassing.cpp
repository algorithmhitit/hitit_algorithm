#include <stdio.h>
#include <iostream>

#define MOD 31991
using namespace std;

int d,t;

struct matrix {
	int arr[55][55] = {};
	//행열의 곱셈을 해주기 위해서 * operator를 만들었다. 
	matrix operator*(matrix a) const{
		matrix ret;//return 값을 저장하기 위한 임시 변수 
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				for(int k=0;k<d;k++){
					ret.arr[i][j] = (ret.arr[i][j] + arr[i][k] * a.arr[k][j]) % MOD; 
				}
			}
		}
		return ret;
	}
}ans,ori;


int main () {
	scanf("%d %d",&d,&t);
	//matrix ori,ans;
	
	for(int i=0;i<d;i++){
		ans.arr[i][i]=ori.arr[0][i]=1;
		if(0<i){
			ori.arr[i][i-1] = 1;
		}
	}
	/*
	이러한 형태의 피보나치 형식의 계산을 위한 배열을 생성 
	1111
	1000
	0100
	0010
	*/
	
	while(t>0){
		if(t%2==1)
            ans=ans*ori;
		ori = ori*ori;
		t = t/2;
	}
	printf("%d",ans.arr[0][0]); 
	return 0;
}
