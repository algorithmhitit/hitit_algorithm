//treeDelete
//
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

tree* treeInsert(tree* r, int x);
void treeDelete(tree* r,int x);
void treePrint(tree* r, int order);

int main(){
    int nodeNum;
    int tmp;
    int deleteNodeNum;
    int typeOfOrder;
    int a[100][2];
    tree* r = NULL;
    scanf("%d", &nodeNum);
    for(int i=0; i<nodeNum; i++){
        scanf("%d", &tmp);
        r=treeInsert(r,tmp);
    }
    scanf("%d", &deleteNodeNum);
    for(int i=0; i<deleteNodeNum; i++){
        scanf("%d %d",&typeOfOrder ,&tmp);
        a[i][0] = typeOfOrder;
        a[i][1] = tmp;
    }

    printf("treeDelete 하기 전\n");

    for(int i=0;i<deleteNodeNum;i++){
        printf("for문 시작 i:%d",i);
        treeDelete(r, a[i][1]);
        printf("tree Delete 완료 i:%d", i);
        treePrint(r, a[i][0]);
        printf("treePrint 완료 i: %d",i);
    }

    printf("treeDelete 한 후\n");

    return 0;
}


tree* treeInsert(tree* r, int x){
    if(r == NULL){
        tree* tmp = (tree*)malloc(sizeof(tree));
        tmp->data = x;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
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

void treeDelete(tree* r,int x){
    printf("treeDelete 시작 x : %d\n",x);
    if(r == NULL){
        return;
    }
    if(r->data > x){
        printf("left! r->data : %d, x : %d\n",r->data,x);
        treeDelete(r->left, x);
    }
    else if(r->data < x){
        printf("right! r->data : %d, x : %d\n",r->data,x);
        treeDelete(r->right,x);
    }
    else if(r->data == x){
        printf("r->data = x! r->data : %d, x : %d\n",r->data,x);
        tree* tmp=NULL,*prev=NULL;
        if(r->right == NULL && r->left == NULL){
            free(r);
            return;
        }
        if(r->left == NULL){
            tmp = r->right;
            while(tmp->left != NULL){
                printf("while!!!!\n");
                prev = tmp;
                tmp = tmp->left;
            }
            if(tmp->right != NULL){
                prev->left = tmp->right;
            }
            printf("after while\n");
            free(tmp);
        }
        else if(r->right == NULL){
            tmp=r->left;
            while(tmp->right != NULL){
                printf("while!!!!\n");
                prev = tmp;
                tmp = tmp->right;
            }
            if(tmp->right != NULL){
                prev->left = tmp->right;
            }
            printf("after while\n");
            free(tmp);
        }

    }
    return;
}

void treePrint(tree* r, int order){
    printf("%d",r->data);
    if(r->left != NULL){
        treePrint(r->left,order);
    }
    //printf("%d",r->data);
    else if(r->right != NULL){
        treePrint(r->right,order);
    }
    //printf("%d",r->data);
    else {
        return;
    }
}
