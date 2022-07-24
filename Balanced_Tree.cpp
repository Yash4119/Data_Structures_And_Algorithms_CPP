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
// int max_depth();
// bool Balanced(Node* root){
//     return max_depth(root)!=-1;
// }

int max_depth(Node* root){
    if(root==NULL)return 0;

    int l = max_depth(root->left);
    if(l==-1)return -1;
    int r = max_depth(root->right);
    if(r==-1)return -1;
    if(abs(l-r)>1)return -1;
    return 1+max(l,r);

    // return 1+max(l,r);
}

int main()
{
    Node* root = new Node(5);
    // root->left = new Node(4);
    root->right = new Node(3);
    // root->left->left = new Node(2);
    root->right->right = new Node(1);

    // cout<<"height of binary tree is :- "<<max_depth(root)<<endl;
    int n = max_depth(root);
    if(n==-1){
        cout<<"Not Balanced"<<endl;

    }
    else{
        cout<<"balanced"<<endl;
    }

    

    return 0;
}