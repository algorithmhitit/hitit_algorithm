//나무조각
//2947번
//https://www.acmicpc.net/problem/2947
//버블 소트를 사용한 문제 풀이
//for문 2개와 swap을 이용하여 bubble sort 구현

#define WOOD 5

//버블소트 함수
void bubbleSort(int size, int a[]);

void printSort(int size, int a[]);

void swapArray(int *a, int *b);

#include <stdio.h>
int main() {
	int a[WOOD];
	for (int i = 0; i < WOOD; i++) {
		scanf("%d", &a[i]);//a[i]번째에 나무조각에 적힌 수를 입력한다.
	}

	bubbleSort(WOOD, a);

	return 0;
}

//이번엔 연습삼아 위에서는 함수의 선언만 해주고 구현은 밑에서 해보았다.
void bubbleSort(int size, int a[]) {
	for (int i = size; i > 0; i--) {
		for (int j = 0; j < i-1; j++) {
			if(a[j]>a[j+1]){
				swapArray(&a[j],&a[j+1]);	
				printSort(size, a);
			}
			
		}
	}
	return;
}

void printSort(int size, int a[]) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

void swapArray(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	return;
}
