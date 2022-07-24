#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelorder(Node *root)
{

    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *n = q.front();
            q.pop();

            if (root->left != NULL)
                q.push(root->left);
            if (root->right != NULL)
                q.push(root->right);

            level.push_back(root->data);
        }

        ans.push_back(level);
    }

    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->right->right = new Node(7);

   v=levelorder(root);
  for(int i=0;i<v.size();i++){
      for(int j=0;j<v.size();j++){
          cout<<v[i][j]<<" ";
      }
      cout<<endl;
  }
   
    // this tree is like this
    //      1
    //     / \
    //    2   3
    //   / \   \
    //   5  4   7

    return 0;
}