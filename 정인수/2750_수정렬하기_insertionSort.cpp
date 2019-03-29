//수정렬하기_insertionSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제풀이방법
//insertion Sort
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

class Sort {
private:
	int a[1000];
	int size;
public:
	void insertionSort(int[]);
	void getSize(int);
	int returnSize();
	void getArray(int, int);
	void printfArray();
};

void Sort::getSize(int a) {
	size = a;
}

void Sort::insertionSort(int a[]) {
	for (int i = 0; i < size; i++) {

	}
}

void Sort::getArray(int val, int i) {
	a[i] = val;
}

int Sort::returnSize() {
	return size;
}

void Sort::printfArray() {
	for (int i = 0; i < size; i++) {
		printf("%d\n", a[i]);
	}
}

int main() {
	Sort sort;
	int size, val;
	scanf("%d", &size);
	sort.getSize(size);
	for (int i = 0; i < sort.returnSize(); i++) {
		scanf("%d", &val);
		sort.getArray(val, i);
	}

	sort.printfArray();

	//Sort::insertinoSort(a);

	return 0;
}