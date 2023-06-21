// Is Height Balanced Binary Tree
// SDE Sheet Q124

int findHeight(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return 0;

    int left = findHeight(node->left);
    int right = findHeight(node->right);

    if (abs(left - right) > 1)
        return -1;
    if (left == -1 || right == -1)
        return -1;

    return max(left, right) + 1;
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;

    return findHeight(root) == -1 ? false : true;
}