// Bottom View Of Binary Tree
// SDE Sheet Q115

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *node = it.first;
        int line_no = it.second;

        mp[line_no] = node->data;

        if (node->left)
            q.push({node->left, line_no - 1});
        if (node->right)
            q.push({node->right, line_no + 1});
    }

    for (auto &ele : mp)
    {
        ans.push_back(ele.second);
    }

    return ans;
}