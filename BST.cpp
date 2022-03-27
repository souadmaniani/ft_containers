#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
    struct Node *parent;
}   BST;

BST *createNode(int data) {
    BST *node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    return node;
}

int numNodes(BST *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

BST * insert(BST *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
// height of a tree
int height(BST *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
// insert iteratively
BST * insertIter(BST *root, int data) {
    BST *node = createNode(data);
    if (root == NULL) {
        return node;
    }
    BST *temp = root;
    while (temp != NULL) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = node;
                node->parent = temp;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = node;
                node->parent = temp;
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}

void inorder(BST *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// inorder data iterative
void inorderTraversal(BST *root) {
    printf("Inorder Traversal: ");
    BST *current = root;
    BST *stack[numNodes(root)];
    int top = -1;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    } 
}

int isLeaf(BST *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return 0;
}

BST * searchIter(BST *root, int data) {
    BST *current = root;
    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

BST * inorderSuccessor(BST *root, int data) {
    BST *current = searchIter(root, data);
    if (current == NULL) {
        return NULL;
    }
    if (current->right != NULL) {
        current = current->right;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    BST *parent = root;
    while (parent != NULL) {
        if (parent->data < data) {
            parent = parent->right;
        } else if (parent->data > data) {
            return parent;
        } else {
            return NULL;
        }
    }

    return parent;
}

BST * deleteNode(BST *root, int data) {
    BST *current = searchIter(root, data);
    if (current == NULL) {
        return root;
    }
    if (!current->left && !current->right)
    {
        if (current->parent->left == current)
        {
            current->parent->left = NULL;
        }
        else
        {
            current->parent->right = NULL;
        }
        free(current);
        return root;
    }
    if (!current->left && current->right)
    {
        current->data = current->right->data;
        return deleteNode(current->right, current->right->data);
    }
    if (current->left && !current->right)
    {
        current->data = current->left->data;
        return deleteNode(current->left, current->left->data);
    }
    if (current->left && current->right)
    {
        BST *successor = inorderSuccessor(root, data);
        current->data = successor->data;
        return deleteNode(successor, successor->data);
    }
    return root;
}

//           10 
//      5           20
//    3    9     15      25

int main() {
    BST *root = NULL;
    root = insertIter(root, 10);
    root = insertIter(root, 5);
    root = insertIter(root, 20);
    root = insertIter(root, 15);
    root = insertIter(root, 3);
    root = insertIter(root, 9);
    root = insertIter(root, 25);
    // BST *Successor = inorderSuccessor(root, 9);
    // if (Successor != NULL) {
    //     printf("Inorder Successor of %d is %d\n", 9, Successor->data);
    // } else {
    //     printf("Inorder Successor of %d is NULL\n", 9);
    // }
    printf("numNodes:%d\n", numNodes(root));
    printf("height: %d\n", height(root));
    inorderTraversal(root);
    deleteNode(root, 20);
    printf("\n");
    inorderTraversal(root);

    return 0;
}

