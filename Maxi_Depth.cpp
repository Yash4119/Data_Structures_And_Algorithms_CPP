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
 
int max_depth(Node* root){
    if(root==NULL)return 0;

    int l = max_depth(root->left);
    int r = max_depth(root->right);

    return 1+max(l,r);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    cout<<"height of binary tree is :- "<<max_depth(root)<<endl;


    return 0;
}