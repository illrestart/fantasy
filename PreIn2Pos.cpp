#include <iostream>
#include <vector>
using namespace std;
class BinaryTree{
    public :
        int value;
        BinaryTree* lChild;
        BinaryTree* rChild;
};
BinaryTree* ConstructCore(int* preStart,int* preEnd,int* inStart,int* inEnd){
    BinaryTree* root = new BinaryTree();
    root->value = preStart[0];
    root->lChild = root->rChild = NULL;

    if(preStart == preEnd){
        if(inStart == inEnd && *preStart == *inStart)
            return root;
        else return NULL;
    }
    int * rootInorder;
    for(rootInorder = inStart;rootInorder <= inEnd && *rootInorder != preStart[0];++rootInorder){}

    if(rootInorder == inEnd && *rootInorder != preStart[0]) return NULL;

    int leftLength = rootInorder - inStart;
    if(leftLength > 0){
        root->lChild = ConstructCore(preStart + 1,preStart +leftLength,
                                     inStart,rootInorder - 1);
    }
    if(leftLength < preEnd - preStart){
        root->rChild = ConstructCore(preStart + leftLength + 1,preEnd,
                                     rootInorder+1,inEnd);
    }
    return root;

}
BinaryTree* ConstructTree(int preOrder[],int inOrder[],int len){
    if(len <= 0 || preOrder == NULL || inOrder == NULL){
        cout<<"NULL"<<endl;
        return NULL;
    }
    else
        return ConstructCore(preOrder,preOrder + len - 1,inOrder,inOrder + len -1 );
}
void PosOrder(BinaryTree* root){
    if(root != NULL){
        PosOrder(root->lChild);
        PosOrder(root->rChild);
        cout<<root->value;
    }
}
int main(){
    int preOrder[] = {1,2,4,7,3,5,6,8};
    int inOrder[] = {4,7,2,1,5,3,8,6};
    int len = sizeof(preOrder)/4;
    BinaryTree* root = ConstructTree(preOrder,inOrder,len);

    PosOrder(root);
    return 0;
}
