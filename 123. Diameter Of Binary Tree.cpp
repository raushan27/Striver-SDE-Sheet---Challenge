// Diameter Of Binary Tree
// SDE Sheet Q123

int findHeight(TreeNode<int> *node)
{
    if (node == NULL)
        return 0;

    int left = findHeight(node->left);
    int right = findHeight(node->right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int currentDiameter = findHeight(root->left) + findHeight(root->right);

    int leftD = diameterOfBinaryTree(root->left);
    int rightD = diameterOfBinaryTree(root->right);

    return max(currentDiameter, max(leftD, rightD));
}