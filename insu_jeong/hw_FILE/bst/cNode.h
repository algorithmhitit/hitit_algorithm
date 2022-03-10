template <typename T>
class cBinarySearchTree;
 
template <typename T>
class cNode{
friend class cBinarySearchTree<T>;
public:
    cNode(){key = 0; left =0;right=0;}
    cNode(T t){key = t; left = right = 0;}
private:
    cNode<T>* left;
    cNode<T>* right;
    T key;
};