// Preorder Traversal
// SDE Sheet Q112

void solve(TreeNode *node, vector<int> &res)
{
    if (node == NULL)
        return;

    res.push_back(node->data);
    solve(node->left, res);
    solve(node->right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    solve(root, res);
    return res;
}