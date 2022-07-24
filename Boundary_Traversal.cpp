#include<iostream>
#include<bits/stdc++.h>
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

bool isleaf(Node* root){
    if(root->left==NULL && root->right==NULL)return 1;

    return 0;
}
vector<int>ans;
void left_boundary(Node* root){
    Node* curr = root->left;
    while(curr){
        if(!isleaf(curr))ans.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else{
            curr = curr->right;
        }
    }
}

void right_boundary(Node* root){
    Node* curr = curr->right;
    vector<int>temp;

    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right)curr = curr->right;
        else{
            curr = curr->left;
        }
    }
    for(int i=temp.size();i>=0;i--){
        ans.push_back(temp[i]);
    }
}

void leaves(Node* root){
    if(isleaf(root)){
        ans.push_back(root->data);
    }

    if(root->left)leaves(root->left);
    if(root->right)leaves(root->right);
}

void boundary(Node* root){
    ans.push_back(root->data);
    left_boundary(root);
    leaves(root);
    right_boundary(root);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    cout<<"boundary order traversal can be given as :- "<<endl;
    boundary(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}