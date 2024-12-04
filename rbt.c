#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define RED   0
#define BLACK 1


struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

struct Node *root;
struct Node *TNULL;

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = RED;
    return node;
}


void preorderHelper(struct Node* node) {
    if (node != TNULL) {
	printf("%d ", node->data);
	preorderHelper(node->left);
	preorderHelper(node->right);
    }
}

void balanceInsert(struct Node* k) {
    struct Node* u;
    while (k->parent->color == RED) {
	if (k->parent == k->parent->parent->right) {
	    u = k->parent->parent->left;
	    if (u->color == RED) {
		u->color = BLACK;
		k->parent->color = BLACK;
		k->parent->parent->color = RED;
		k = k->parent->parent;
	    } else {
		if (k == k->parent->left) {
		    k = k->parent;
		    rightRotate(k);
		}
		k->parent->color = BLACK;
		k->parent->parent->color = RED;
		leftRotate(k->parent->parent);
	    }
	} else {
	    u = k->parent->parent->right;
	    if (u->color == RED) {
		u->color = BLACK;
		k->parent->color = BLACK;
		k->parent->parent->color = RED;
		k = k->parent->parent;
	    } else {
		if (k == k->parent->right) {
		    k = k->parent;
		    leftRotate(k);
		}
		k->parent->color = BLACK;
		k->parent->parent->color = RED;
		rightRotate(k->parent->parent);
	    }
	}
	if (k == root) break;
    }
    root->color = BLACK;
}

int leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
	y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
	root = y;
    } else if (x == x->parent->left) {
	x->parent->left = y;
    } else {
	x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    return 0;
}

int rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
	y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
	root = y;
    } else if (x == x->parent->right) {
	x->parent->right = y;
    } else {
	x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    return 0;
}
void insert(int key) {
    struct Node* node = createNode(key);
    struct Node* y = NULL;
    struct Node* x = root;

    while (x != TNULL) {
	y = x;
	if (node->data < x->data) {
	    x = x->left;
	} else {
	    x = x->right;
	}
    }
    node->parent = y;
    if (y == NULL) {
	root = node;
    } else if (node->data < y->data) {
	y->left = node;
    } else {
	y->right = node;
    }

    node->left = TNULL;
    node->right = TNULL;
    node->color = RED;

    balanceInsert(node);
}
void initialize() {
    TNULL = (struct Node*)malloc(sizeof(struct Node));
    TNULL->color = BLACK;
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
}
void printTree(struct Node* root, int space) {
    int i;
    if (root == TNULL) {
	return;
    }

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for ( i = 10; i < space; i++) {
	printf(" ");
    }
    printf("%d(%s)\n", root->data, root->color == RED ? "R" : "B");

    printTree(root->left, space);
}

void displayMenu() {
    printf("\nRed-Black Tree Menu:\n");
    printf("1. Insert a node\n");
    printf("2. Display Preorder Traversal\n");
    printf("3. Display Tree Structure\n");
    printf("4. Exit\n");
}

void main() {
    int choice, data;


    initialize();

    while (1) {
	displayMenu();
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to insert: ");
		scanf("%d", &data);
		insert(data);
		printf("Node inserted successfully.\n");
		break;

	    case 2:
		printf("Preorder Traversal of the Red-Black Tree:\n");
		preorderHelper(root);
		printf("\n");
		break;

	    case 3:
		printf("Tree Structure (Right rotated view):\n");
		printTree(root, 0);
		break;

	    case 4:
		printf("Exiting...\n");
		exit(0);
		break;

	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }
}