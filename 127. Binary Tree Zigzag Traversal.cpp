// Binary Tree Zigzag Traversal
// SDE Sheet Q127

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> result;
    queue<BinaryTreeNode<int> *> q;

    bool lefttoright = true;

    if (root == NULL)
        return result;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> sub;
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();

            // int index=lefttoright?i:n-i-1;
            sub.push_back(curr->data);

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        if (lefttoright == false)
            reverse(sub.begin(), sub.end());
        for (auto i : sub)
        {
            result.push_back(i);
        }
        lefttoright = !lefttoright;
    }
    return result;
}