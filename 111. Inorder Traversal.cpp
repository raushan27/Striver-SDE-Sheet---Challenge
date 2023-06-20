// Inorder Traversal
// SDE Sheet Q111

void solve(TreeNode *node, vector<int> &res)
{
    if (node == NULL)
        return;

    solve(node->left, res);
    res.push_back(node->data);
    solve(node->right, res);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    solve(root, res);
    return res;
}