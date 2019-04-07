//a,b 가 주어젔을 때  를 1000000007로 나눈 나머지를 출력하시오
//조건 1 <= b <= 10^15		1<= a < 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long f(long long a,long long b) {
	long long result;
	if(b == 1){
		return a;
	}
	else if (0 == (int)b % 2) {
		//차수가 짝수일 때
		b = b / 2;
		result = pow(f(a,b),2);
	}
	else if (1 == (int)b % 2) {
		//차수가 홀수일 때
		b = (b - 1) / 2;
		result = a*pow(f(a, b), 2);
	}
	return result;
}

int main() {
	long long result;
	long long a=0, b=0;

	printf("a에 b승값을 입력하시요 : ");
	scanf("%lld %lld", &a, &b);

	result = f(a,b);

	printf("%lld %lld", result, result%1000000007);

	return 0;
}