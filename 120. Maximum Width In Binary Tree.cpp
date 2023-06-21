// Maximum Width In Binary Tree
// SDE Sheet Q120

int getMaxWidth(TreeNode<int> *root) // simple level order traversal
{
    if (root == NULL)
        return 0;

    int maxWidth = 0;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        maxWidth = max(maxWidth, n);
        while (n--)
        {
            TreeNode<int> *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return maxWidth;
}