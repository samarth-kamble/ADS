#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *createTree()
{
    struct Node *root = NULL;
    int rootKey;
    printf("Enter the key for the root node: ");
    scanf("%d", &rootKey);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->key = rootKey;
    root->left = root->right = NULL;
    return root;
}

struct Node *insertNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

void levelwiseTraversal(struct Node *root)
{
    if (!root)
        return;

    struct Node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear)
    {
        struct Node *current = queue[++front];
        printf("%d ", current->key);

        if (current->left)
            queue[++rear] = current->left;
        if (current->right)
            queue[++rear] = current->right;
    }
}

void mirrorImage(struct Node *root)
{
    if (root)
    {
        struct Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorImage(root->left);
        mirrorImage(root->right);
    }
}

int heightOfTree(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void leafNodeDisplay(struct Node *root)
{
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->key);
        leafNodeDisplay(root->left);
        leafNodeDisplay(root->right);
    }
}

int main()
{
    struct Node *root = createTree();

    // Example usage:
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Levelwise Traversal: ");
    levelwiseTraversal(root);
    printf("\n");

    printf("Mirror Image: ");
    mirrorImage(root);
    inorderTraversal(root); // Displaying the modified tree
    printf("\n");

    printf("Height of the tree: %d\n", heightOfTree(root));

    printf("Leaf Nodes: ");
    leafNodeDisplay(root);
    printf("\n");

    free(root); // Remember to free allocated memory

    return 0;
}
