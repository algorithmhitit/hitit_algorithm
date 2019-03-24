//트리순회
//1991번
//https://www.acmicpc.net/problem/1991
//2진트리의 구조체를 구현해서 순회 방식대로 출력한다.
#include <stdio.h>
using namespace std;

//이진트리 구조체 노드
struct node {
    char code;
    node *left;//왼쪽 노드 포인터
    node *right;//오른쪽 노드 포인터
};

void preOrder(int i,node tree[]){
    if(i<26 || i>=0){
        printf("%c",tree[i].code);
        //printf("%c %c %c",tree[i].code, tree[i].left->code, tree[i].right->code);
        if(tree[i].left->code != '.'){
            //printf("\n tree[%d].left->code-65 = %d %c\n",i,(tree[i].left->code)-65,tree[i].left->code);
            //printf("\n left = %c\n",tree[i].left->code);
            preOrder((int)(tree[i].left->code)-65,tree);
        }
        if(tree[i].right->code !='.'){
            //printf("\n right = %c\n",tree[i].right->code);
            preOrder((int)(tree[i].right->code)-65,tree);
        }
    }
    return;
}

void inOrder(int i,node tree[]){
    if(i<26 || i>=0){
        //printf("%c %c %c",tree[i].code, tree[i].left->code, tree[i].right->code);
        if(tree[i].left->code != '.'){
            //printf("\n tree[%d].left->code-65 = %d %c\n",i,(tree[i].left->code)-65,tree[i].left->code);
            //printf("\n left = %c\n",tree[i].left->code);
            inOrder((int)(tree[i].left->code)-65,tree);
        }
        printf("%c",tree[i].code);
        if(tree[i].right->code !='.'){
            //printf("\n right = %c\n",tree[i].right->code);
            inOrder((int)(tree[i].right->code)-65,tree);
        }
    }
    return;
}

void postOrder(int i,node tree[]){
    if(i<26 || i>=0){
        //printf("%c %c %c",tree[i].code, tree[i].left->code, tree[i].right->code);
        if(tree[i].left->code != '.'){
            //printf("\n tree[%d].left->code-65 = %d %c\n",i,(tree[i].left->code)-65,tree[i].left->code);
            //printf("\n left = %c\n",tree[i].left->code);
            postOrder((int)(tree[i].left->code)-65,tree);
        }
        if(tree[i].right->code !='.'){
            //printf("\n right = %c\n",tree[i].right->code);
            postOrder((int)(tree[i].right->code)-65,tree);
        }
        printf("%c",tree[i].code);
    }
    return;
}

int main () {
    node tree[27];//알파뱃 대문자로 이루어진 이진트리
    for(int i=0; i<27;i++){
        tree[i].code = '.';//알파뱃 대문자로 이루어진 이진트리
    }
    int size = 0;
    int index = 0;
    char a,b,c;
    scanf("%d",&size);//노드의 개수를 받아준다.
    for(int i=0; i<size; i++){
        scanf("\n%c %c %c", &a, &b, &c);
        //scanf("%c ",&tree[tree[i].left.code-65]);
        index = a-65;
        if(b == '.')
            tree[index].left = &tree[26];
        else
            tree[index].left = &tree[b-65];
        if(c == '.')
            tree[index].right = &tree[26];
        else
            tree[index].right = &tree[c-65];
        tree[index].code = a;
        tree[index].left->code = b;
        tree[index].right->code = c;
    }
    //ascii코드는 10진 65부터 문자 A를 받는다.
    //전위순회
    int i=0;
    preOrder(i,tree);
    printf("\n");
    //중위순회
    inOrder(i,tree);
    printf("\n");
    //후위 순회
    postOrder(i,tree);

    return 0;
}