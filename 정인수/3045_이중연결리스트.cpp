//이중연결리스트
//3045번
//https://www.acmicpc.net/problem/3045
#include <stdio.h>
#include <iostream>
using namespace std;
int a[500000];

struct linkedNode {
	int data;
	linkedNode *prev;
	linkedNode *next;
};

int main () {
	int nodeNum, calNum;
	char state;
	int x, y;
	linkedNode node[500000]
	scanf("%d %d",&nodeNum, &calNum);
	for (int i = 0; i < nodeNum; i++) {
		node[i].data = i + 1;
		if (i == 0) {
			node[i].prev = NULL;
		}
		else {
			node[i].prev = &node[i - 1];
		}
		
		if (i == nodeNum-1) {
			node[i].next = NULL;
		}
		else {
			node[i].next = &node[i + 1];
		}
	}

	for (int i = 0; i < nodeNum; i++) {
		scanf("%c %d %d",&state,&x,&y);
		x = x - 1;
		y = y - 1;
		if (state == 'A') {
			node[x].prev->next = node[x].next;
			node[x].next->prev = node[x].prev;
			node[x].next = &node[y];
			node[x].prev = node[y]->prev;
			node[y].prev->next = &node[x];
			node[y].prev = &node[x];
		}
		else if (state == 'B') {
			node[x].prev->next = node[x].next;
			node[x].next->prev = node[x].prev;
			node[x].next = node[y].next;
			node[x].prev = &node[y];
			node[y].next->prev = &node[x];
			node[y].next = &node[y];
		}
	}

	while (node[x]->next != NULL) {
		printf("%d", node[x].data);
	}

	return 0;
}
