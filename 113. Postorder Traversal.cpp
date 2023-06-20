// Postorder Traversal
// SDE Sheet Q113

void solve(TreeNode *node, vector<int> &res)
{
    if (node == NULL)
        return;

    solve(node->left, res);
    solve(node->right, res);
    res.push_back(node->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    solve(root, res);
    return res;
}