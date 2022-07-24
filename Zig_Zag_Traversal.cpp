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

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> v;
    if(root==NULL){
        return v;
    }
    queue<Node*>q;
    q.push(root);
    bool ltr = true;            // ltr = left to right
    while(!q.empty()){
        int size = q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            int index = (ltr)? i : (size-1-i);
            row[index] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        ltr = !ltr;
        v.push_back(row);

    }
    return v;

}
 
int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    vector<vector<int>>v;

     v=zigzag(root);
  for(int i=0;i<v.size();i++){
      for(int j=0;j<v[i].size();j++){
          cout<<v[i][j]<<" ";
      }
      cout<<endl;
  }

    return 0;
}