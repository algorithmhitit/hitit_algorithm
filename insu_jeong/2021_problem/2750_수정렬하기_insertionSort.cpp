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
	Sort();
	~Sort();
	void insertionSort();
	void getSize(int);
	int returnSize();
	void getArray(int, int);
	void printfArray();
};

Sort::Sort() {
	this->size = 0;
}

Sort::~Sort() {}

void Sort::insertionSort() {
	int temp;
	for (int i = 0; i < size; i++) {
		temp = a[i];
		for (int j = 0 ; j < i ; j++) {
			if(a[i]<a[j]){
				a[i] = a[j];
				a[j] = temp;
				temp = a[i];
			}
		}
	}
}

void Sort::getSize(int a) {
	size = a;
}

int Sort::returnSize() {
	return size;
}

void Sort::getArray(int val, int i) {
	a[i] = val;
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

	sort.insertionSort();

	sort.printfArray();

	return 0;
}