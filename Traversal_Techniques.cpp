// #include<iostream>
#include<bits/stdc++.h>
// #include<vector>
// #include<queue>
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
void PreOrder_Traversal(Node* root){
    if(root==NULL)return;

    cout<<root->data<<"  ";
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
}

void InOrder_Traversal(Node* root){
    if(root==NULL){
        return;
    }

    InOrder_Traversal(root->left);
    cout<<root->data<<"  ";
    InOrder_Traversal(root->right);
}

void PostOrder_Traversal(Node* root){
    if(root==NULL){
        return;
    }

    PostOrder_Traversal(root->left);
    PostOrder_Traversal(root->right);
    cout<<root->data<<"  ";
}

vector<vector<int>> LevelOrder_Traversal(Node* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            Node* ptr = q.front();
            q.pop();
            if(ptr->left != NULL)
                q.push(ptr->left);
            
            if(ptr->right != NULL)
                q.push(ptr->right);
            
            v.push_back(ptr->data);
        }
        ans.push_back(v);
    }
    return ans;
}
 
int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    //  Tree 
    //               5   
    //             /   \
    //            4     3
    //           / \   / \ 
    //         2 NULL NULL 1 

    cout<<"Pre Order Traversal"<<endl;
    PreOrder_Traversal(root);
    // [ 5 , 4 , 2 , 3 , 1 ]

    cout<<endl;
    cout<<"InOrder Traversal"<<endl;
    InOrder_Traversal(root);
    // [ 2 , 4 , 5 , 3 , 1 ]

    cout<<endl;
    cout<<"Post Order Traversal"<<endl;
    PostOrder_Traversal(root);
    // [ 2 , 4 , 1 , 3 , 5 ]

    cout<<endl;

    vector<vector<int>>vec;
    cout<<"Level order Traversal"<<endl;
    vec = LevelOrder_Traversal(root);
    // [ 5 , 4 , 3 , 2 , 1 ]

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }   
        cout << endl;
    }

    return 0;
}