// Top View Of Binary Tree
// SDE Sheet Q116

vector<int> getTopView(TreeNode<int> *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line_no = it.second;

        if (mp.find(line_no) == mp.end()) // saw that line_no for first time
            mp[line_no] = node->val;      // only update the first time you encounter a new line

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