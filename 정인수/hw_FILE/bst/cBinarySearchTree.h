#include "cNode.h"
#include <iostream>
using namespace std;
 
template <typename T>
class cBinarySearchTree{
friend class cNode<T>;
public:
    cBinarySearchTree();
    ~cBinarySearchTree();
    void treeInsert(T x);
    void treeDelete(T x);
    void treePrint();
private:
    cNode<T>* treeInsert(cNode<T>* t, T x);
    void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);   
    cNode<T>* deleteNode(cNode<T>* r);
    void treePrint(cNode<T>* t, int step);
    cNode<T>* root;
};