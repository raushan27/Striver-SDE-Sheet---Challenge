// Tree Traversals
// SDE Sheet Q117

void inorder(BinaryTreeNode<int> *node, vector<int> &in)
{
    if (node == NULL)
        return;

    inorder(node->left, in);
    in.push_back(node->data);
    inorder(node->right, in);
}

void preorder(BinaryTreeNode<int> *node, vector<int> &pre)
{
    if (node == NULL)
        return;

    pre.push_back(node->data);
    preorder(node->left, pre);
    preorder(node->right, pre);
}

void postorder(BinaryTreeNode<int> *node, vector<int> &post)
{
    if (node == NULL)
        return;

    postorder(node->left, post);
    postorder(node->right, post);
    post.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> res;
    vector<int> in, pre, post;

    inorder(root, in);
    preorder(root, pre);
    postorder(root, post);

    res.push_back(in);
    res.push_back(pre);
    res.push_back(post);

    return res;
}