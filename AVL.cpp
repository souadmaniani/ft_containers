#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
    struct Node *parent;
    int height;
}   AVL;

// height of a node
int height(AVL *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// newNode 
AVL * createNode(int data) {
    AVL *node = (AVL *)malloc(sizeof(AVL));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    node->height = 1;
    return node;
}

void inorder(AVL *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//example of left rotate
// 2                                     3                       2                     2
//  \   */                              / \  */                 / \  */               / \ */
//   3              ====>              2   4                   1   4    ====>        1   6
//    \   */                                                        \  */               / \ */
//     4                                                              6                4   7
//                                                                     \   */
//                                                                      7      
// max of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

int getBalance(AVL *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}
//          4
//      3           ==>         3
//  2                       2         4
// right rotate
AVL * rightRotate(AVL *root) {
    printf("right rotate\n");
    // 4 3 2
    AVL *temp = root->left;
    AVL *temp2 = temp->right;
    temp->right = root;
    root->left = temp2;
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}
// left rotate
AVL * leftRotate(AVL *root) {
    // printf("left rotate\n");
    // 1 2 4 6 7
    // printf("root: %d\n", root->data);
    AVL *temp = root->right; // 
    AVL *temp2 = temp->left; // 
    temp->left = root;  //
    root->right = temp2; //
    root->parent = temp; //
    temp->parent = NULL; // 
    root->height = max(height(root->left), height(root->right)) + 1; // 
    temp->height = max(height(temp->left), height(temp->right)) + 1; // 
    // printf("temp: %d\n", temp->data);
    // printf("temp left %d\n", temp->left->data);
    // printf("temp right %d\n", temp->right->data);

    return temp;
}

// insert
AVL * insert(AVL *root, int data) {

    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }
    printf("root: %d ", root->data);
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    // left rotate
    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    // right rotate
    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }
    // left right
    // if (balance > 1 && data > root->left->data) {
    //     root->left = leftRotate(root->left);
    //     return rightRotate(root);
    // }
    // // right left
    // if (balance < -1 && data < root->right->data) {
    //     root->right = rightRotate(root->right);
    //     return leftRotate(root);
    // }
    
    return root;
}
int main()
{
    AVL *root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 7);
    inorder(root);
    printf("\n");
    printf("left: %d\n", root->left->data);
    printf("right: %d\n", root->right->data);
    printf("height: %d\n", root->height);
    return 0;
}