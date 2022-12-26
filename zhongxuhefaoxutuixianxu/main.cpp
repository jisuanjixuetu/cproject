#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value):val(value), left(nullptr), right(nullptr) {}
};
TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd)
{
    if(postorderBegin == postorderEnd) return nullptr;

    int rootValue = postorder[postorderEnd - 1];
    TreeNode* root = new TreeNode(rootValue);   //创建父亲节点

    if(postorderEnd - postorderBegin == 1) return root;

    int delimiterIndex;     //分割位置的下标
    for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; ++delimiterIndex) if(inorder[delimiterIndex] == rootValue) break;

    root->left = traversal(inorder, inorderBegin, delimiterIndex, postorder, postorderBegin, postorderBegin + delimiterIndex - inorderBegin);
    root->right = traversal(inorder, delimiterIndex + 1, inorderEnd, postorder, postorderBegin + delimiterIndex - inorderBegin, postorderEnd - 1);

    return root;
}
void Preorder(TreeNode* node) {
    if(node == nullptr) return;
    cout << " " << node->val;
    Preorder(node->left);
    Preorder(node->right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for(int i = 0; i < n; ++i) cin >> postorder[i];
    for(int i = 0; i < n; ++i) cin >> inorder[i];
    cout << "Preorder:";
    Preorder(traversal(inorder, 0, n, postorder, 0, n));
    return 0;
}

