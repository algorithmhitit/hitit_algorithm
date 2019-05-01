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
tree* treeDelete(tree* r,int x);
tree* minValueNode(tree* r);
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

    for(int i=0;i<deleteNodeNum;i++){
        treeDelete(r, a[i][1]);
        treePrint(r, a[i][0]);
        printf("\n");
    }

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

tree* treeDelete(tree* r,int x){
    if(r == NULL){
        return r;
    }
    if(r->data > x){
        r->left = treeDelete(r->left, x);
    }
    else if(r->data < x){
        r->right = treeDelete(r->right,x);
    }
    else if(r->data == x){
        if(r->left == NULL){
            tree *temp = r->right;
            free(r);
            return temp;
        }
        else if(r->right == NULL){
            tree *temp = r->left;
            free(r);
            return temp;
        }
        tree* temp = minValueNode(r->right);
        r->data = temp->data;
        r->right = treeDelete(r->right,temp->data);
    }
    return r;
}

tree* minValueNode(tree* r){
    tree* current = r;
    while(current->left !=NULL)
        current = current->left;
    return current;
}

void treePrint(tree* r, int order){
    if(order == 0)printf("%d ",r->data);
    if(r->left != NULL){
        treePrint(r->left,order);
    }
    if(order == 1)printf("%d ",r->data);
    if(r->right != NULL){
        treePrint(r->right,order);
    }
    if(order == 2)printf("%d ",r->data);
}
