// Implement the BST with the following individual functions.
// 1. Create new node
// 2. Insert a new node to the BST
// 3. Pre-order, In-order, and Post-order traversal
// 4. Search an element from BST
// 5. Find the smallest and largest element from BST
// 6. Find the height of the BST




#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    struct TreeNode *left;
    int val;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data);
struct TreeNode *insert(struct TreeNode *root, int k);
void inorderTraversal(struct TreeNode *root);
struct TreeNode *search(struct TreeNode *root, int k);
int findSmallestElement(struct TreeNode *root);
int findLargestElement(struct TreeNode *root);
int findHeight(struct TreeNode *root);
void displayTree(struct TreeNode *root);

int main()
{
    struct TreeNode *root = NULL;
    int choice, key;

    do
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Element\n");
        printf("2. Inorder Traversal\n");
        printf("3. Search Element\n");
        printf("4. Find Smallest Element\n");
        printf("5. Find Largest Element\n");
        printf("6. Find Height of the Tree\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                struct TreeNode *result = search(root, key);
                if (result)
                    printf("Element found in the tree.\n");
                else
                    printf("Element not found in the tree.\n");
                break;
            case 4:
                printf("Smallest Element: %d\n", findSmallestElement(root));
                break;
            case 5:
                printf("Largest Element: %d\n", findLargestElement(root));
                break;
            case 6:
                printf("Height of the Tree: %d\n", findHeight(root));
                break;
            case 7:
                printf("Tree Elements: ");
                displayTree(root);
                printf("\n");
                break;
            case 8:
                // Free memory before exiting
                free(root);
                printf("Exiting program. Memory freed.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}


struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("Memory Error");
        return NULL;
    }

    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int k)
{
    if (root == NULL)
        return createNode(k);

    if (k < root->val)
        root->left = insert(root->left, k);

    if (k > root->val)
        root->right = insert(root->right, k);

    return root;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

struct TreeNode *search(struct TreeNode *root, int k)
{
    if (root == NULL || root->val == k)
        return root;

    if (k < root->val)
        return search(root->left, k);

    return search(root->right, k);
}

int findSmallestElement(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->val;
}

int findLargestElement(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->val;
}

int findHeight(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

void displayTree(struct TreeNode *root)
{
    if (root != NULL)
    {

        displayTree(root->left);

        printf("%d ", root->val);

        displayTree(root->right);
    }
}