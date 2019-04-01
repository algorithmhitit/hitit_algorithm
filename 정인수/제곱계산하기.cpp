//a,b 가 주어젔을 때  를 1000000007로 나눈 나머지를 출력하시오
//조건 1 <= b <= 10^15		1<= a < 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long f(long a,long b) {
	long result;
	if(b == 1){
		return a;
	}
	else if (0 == (int)b % 2) {
		//차수가 짝수일 때
		b = b / 2;
		result = pow((double)f(a,b), (double)2);
	}
	else if (1 == (int)b % 2) {
		//차수가 홀수일 때
		b = (b - 1) / 2;
		result = a*pow((double)f(a, b), (double)2);
	}
	return result;
}

int main() {
	long result;
	long a=0, b=0;

	printf("a에 b승값을 입력하시요 : ");
	scanf("%ld %ld", &a, &b);

	result = f(a,b);

	printf("%ld", result);

	return 0;
}