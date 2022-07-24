#include<iostream>
#include<vector>
#include<stack>

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

vector<int> Combined_Traversal(Node* root){

    stack<pair<Node*,int>>st;
    vector<int>pre,post,in;
    if(root==NULL)return{0};
    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left !=NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right !=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }

    // return pre;
    // return in;
    return post;

}

 
int main()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->right->right = new Node(1);

    vector<int>v;
    v = Combined_Traversal(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    // inorder// [ 2 , 4 , 5 , 3 , 1 ]
    // Preorder// [ 5 , 4 , 2 , 3 , 1 ]
    // PostOrder// [ 2 , 4 , 1 , 3 , 5 ]
    return 0;
}