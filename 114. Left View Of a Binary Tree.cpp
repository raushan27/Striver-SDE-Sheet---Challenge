// Left View Of a Binary Tree
// SDE Sheet Q114

void bfs(TreeNode<int> *root, vector<int> &res)
{ // using BFS
    if (root == NULL)
        return;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();

        res.push_back(q.front()->data);

        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *curr_node = q.front();
            q.pop();
            if (curr_node->left)
                q.push(curr_node->left);
            if (curr_node->right)
                q.push(curr_node->right);
        }
    }
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    bfs(root, res);
    return res;
}

// DFS but by using trick by comparing res vector size by level
void solve(TreeNode<int> *node, vector<int> &res, int level)
{
    if (node == NULL)
        return;

    if (res.size() == level) // seen first element in that level
        res.push_back(node->data);

    solve(node->left, res, level + 1);
    solve(node->right, res, level + 1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    solve(root, res, 0);
    return res;
}