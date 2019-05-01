//binarySearchTree
//template로 구현하기
#include <stdio.h>
#include "cBinarySearchTree.h"

template <typename T>
void cBinarySearchTree<t>::treeInsert(T x){
    root = treeInsert(root, x);
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(T x){
    cNode<T>* r = root;
    cNode<T>* p = 0;
 
    // r의 부모를 찾아 p에 저장
 
    if(r)       treeDelete(root, r, p);
}

int main() {
    
}