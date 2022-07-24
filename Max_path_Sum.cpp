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

int calc(Node* root, int& maxi){
    if(root==NULL)return 0;

    int lh = max(0,calc(root->left,maxi));
    int rh = max(0,calc(root->right,maxi));

    maxi = max(maxi,lh+rh+root->data);
    
    return root->data+max(lh,rh);

    }

int Max_PathSum(Node* root){
    int maxi =INT_MIN;
    calc(root,maxi);
    return maxi;
}
 
int main()
{
    Node* root = new Node(5);
    root->left = new Node(-4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    cout<<"Max Path SUm Of the Binary Tree is :- "<<Max_PathSum(root)<<endl;

    return 0;
}
    
    
    
    //  Tree 
    //               5   
    //             /   \
    //           -4     3
    //           / \   / \ 
    //         2 NULL NULL 1 
