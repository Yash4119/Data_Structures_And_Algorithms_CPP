#include<bits/stdc++.h>
using namespace std;

class tree{
public:
    int data;
    tree* left;
    tree* right;

    tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void child_sum_prop(tree* root){
    if(root == NULL){
        return;
    }

    int child_sum = 0;
    if(root->left){
        child_sum += root->left->data;
    }
    if(root->right){
        child_sum += root->right->data;
    }

    if(root->data <= child_sum){
        root->data = child_sum;
    }
    else{
        if(root->left){
            root->left->data = root->data;
        }
        else if(root->right){
            root->right->data = root->data;
        }
    }

    child_sum_prop(root->left);
    child_sum_prop(root->right);

    int tot = 0;
    if(root->left){
        tot += root->left->data;
    }
    if(root->right){
        tot += root->right->data;
    }
    if(root->left or root->right){
        root->data = tot;
    }

}
 
void display(tree* root){
    if(root == NULL){
        return;
    }

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main()
{
    tree* t = new tree(40);

    t->left = new tree(10);
    t->right = new tree(20);
    t->left->left = new tree(2);
    t->left->right = new tree(5);
    t->right->left = new tree(30);
    t->right->right = new tree(40);

    display(t);
    cout<<endl;

    child_sum_prop(t);

    display(t);
    cout<<endl;
 
    return 0;
}