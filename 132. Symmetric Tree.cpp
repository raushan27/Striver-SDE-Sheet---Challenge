// Symmetric Tree
// SDE Sheet Q132

bool check(BinaryTreeNode<int> *leftNode, BinaryTreeNode<int> *rightNode)
{
    if (leftNode == NULL || rightNode == NULL)
        return leftNode == rightNode;

    if (leftNode->data != rightNode->data)
        return false;

    return check(leftNode->left, rightNode->right) && check(leftNode->right, rightNode->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;

    return check(root->left, root->right);
}