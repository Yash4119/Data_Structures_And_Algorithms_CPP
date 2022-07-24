#include<iostream>
using namespace std;
 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
 
bool is_Same(Node* p,Node* q){
    if(p==NULL || q==NULL)return (p==q);

    return (p->data==q->data) && (is_Same(p->left,q->left)) && (is_Same(p->right,q->right));
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);
    
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(3);
    root2->left->left = new Node(2);
    root2->right->right = new Node(1);

    if(is_Same(root,root2)){
        cout<<"The given Trees are Identical ......."<<endl;
    }
    else{
        cout<<"Given Trees are not Identical ........"<<endl;
    }

    return 0;
}