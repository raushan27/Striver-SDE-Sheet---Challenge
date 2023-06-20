// Vertical Order Traversal
// SDE Sheet Q118

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    mp[0].push_back(root->data);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line_no = it.second;

        if (node->left)
        {
            q.push({node->left, line_no - 1});
            mp[line_no - 1].push_back(node->left->data);
        }

        if (node->right)
        {
            q.push({node->right, line_no + 1});
            mp[line_no + 1].push_back(node->right->data);
        }
    }

    for (auto &vec : mp)
    {
        for (auto &i : vec.second)
            ans.push_back(i);
    }

    return ans;
}