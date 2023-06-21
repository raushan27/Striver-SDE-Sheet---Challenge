// Level Order Traversal
// SDE Sheet Q121

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};

    vector<int> res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            res.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return res;
}