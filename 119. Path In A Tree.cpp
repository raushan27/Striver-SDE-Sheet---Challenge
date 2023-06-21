// Path In A Tree
// SDE Sheet Q119

void solve(TreeNode<int> *node, vector<int> &res, int &x)
{
    if (node == NULL)
        return;

    res.push_back(node->data);
    if (node->data == x)
        return;

    solve(node->left, res, x);
    solve(node->right, res, x);

    if (res[res.size() - 1] != x)
        res.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;

    solve(root, res, x);
    return res;
}