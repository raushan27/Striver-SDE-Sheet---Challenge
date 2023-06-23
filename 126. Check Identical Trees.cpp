// Check Identical Trees
// SDE Sheet Q126

bool check(BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    if (node1 == NULL || node2 == NULL)
        return node1 == node2;

    if (node1->data != node2->data)
        return false;

    return check(node1->left, node2->left) && check(node1->right, node2->right);
}

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    return check(root1, root2);
}