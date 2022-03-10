//treeInsert
//Binary search tree
//treeInsert함수가 호출되는 횟수를 출력하라
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct tree {
    int data;
    tree* left;
    tree* right;
};

int count=0;

tree* treeInsert(tree* r, int x);

int main(){
    int nodeNum;
    int tmp;
    tree* r = NULL;
    scanf("%d", &nodeNum);
    for(int i=0; i<nodeNum; i++){
        scanf("%d", &tmp);
        r=treeInsert(r,tmp);
    }
    printf("%d",count);
    return 0;
}


tree* treeInsert(tree* r, int x){
    count++;
    if(r == NULL){
        tree* a = (tree*)malloc(sizeof(tree));
        a->data = x;
        a->left = NULL;
        a->right = NULL;
        return a;
    }
    if(x< r->data){
        r->left = treeInsert(r->left,x);
        return r;
    }
    else {
        r->right = treeInsert(r->right,x);
        return r;
    }
}