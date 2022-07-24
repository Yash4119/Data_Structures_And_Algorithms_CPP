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

//  Tree 
    //               5   
    //             /   \
    //            4     3
    //           / \   / \ 
    //         2 NULL NULL 1 
 
int dia(Node* root,int& diameter){
    if(root==NULL)return 0;

    int lh = dia(root->left,diameter);
    int rh = dia(root->right,diameter);

    diameter = max(diameter,lh+rh);
    return 1+max(lh,rh);
}
// i
int Diameter(Node* root){
    int diameter=0;
    dia(root,diameter);
    return diameter;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    int Diam = Diameter(root);
    cout<<"The max diameter of the tree is :- "<<Diam<<endl;
 
    return 0;
}