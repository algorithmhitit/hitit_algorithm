//binarySearchTree
//template로 구현하기
//컴파일 방식
//g++ -o test binarySearchTree.cpp cNode.h cBinarySearchTree.h
//이러면 test.exe가 해당 폴더에 생성된다.

#include "cBinarySearchTree.h"
#include <iostream>
using namespace std;
 
int main(){
    char cmd;
    int n, x;
    cBinarySearchTree<int> tree;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>cmd>>x;
        switch(cmd){
        case 'I':
            tree.treeInsert(x);
            break;
        case 'D':
            tree.treeDelete(x);
            break;
        }
    }
    tree.treePrint();
    return 0;
}