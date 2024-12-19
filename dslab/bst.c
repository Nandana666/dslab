// Including necessary header files
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    // Allocate memory for a new TreeNode
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    // Check if memory allocation was successful
    if (newNode != NULL) {
        // Initialize node data
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    // Return the created node
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // If the value is less than the root's data, insert into the left subtree
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // If the value is greater than the root's data, insert into the right subtree
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    // Return the modified root
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    // Traverse the tree in-order: left subtree, root, right subtree
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void preOrder(struct TreeNode* root)
{
    if (root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct TreeNode* root)
{

    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}
// Function to free the memory allocatinted for the binary tree
struct TreeNode* findMin(struct TreeNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        printf("The value to be deleted is not present inside the tree\n");
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
	    printf("\n deleted succesfulluy \n");
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
	    printf("\n deleted succesfulluy \n");

            return temp;
        }
       
        // Node with two children
        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int search(struct TreeNode* root){
	int s;
	printf("\n Enter value to be search:");
	scanf("%d",&s);
	while(root!=NULL && root->data!=s){
		if(s<root->data)
			root=root->left;
		else
			root=root->right;
	}
	return root;
}

int main() {
    // Inprintf("Input a value to insert into the binary tree: ");
        //scanf("%d", &nodeValue);

        // Insert the value into the binary tree
       // root = insertNode(root, nodeValue);
//itialize the root of the binary tree
    struct TreeNode* root = NULL;
    int nodeValue,value;
    struct TreeNode* found = NULL;
  //  struct TreeNode* delete=NULL;
    char choice;
	int data,ch;
    do{
            printf("\n MENU \n 1.insert \n 2.delete \n 3.search \n4.inorder \n 5.preorder \n 6.postorder \n7.exit");

            printf("\n enter your choice:");
            scanf("%d",&ch);

            switch(ch){

                case 1: printf("Input a value to insert into the binary tree: ");
        	        scanf("%d", &nodeValue);

        // Insert the value into the binary tree
		      	 root = insertNode(root, nodeValue);

                        
                        break;
                case 2: if (root == NULL)
                    printf("Tree is empty.\n");
                else{
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
               
                }
                        break;
                case 3: found=search(root);
			if(found!=NULL)
				printf("found");
			else
				printf("not found");
                        break;
                case 4: inOrderTraversal(root);
                        break;
		case 5: preOrder(root);
                        break;
		case 6: postOrder(root);
                        break;

                case 7: printf("\n EXIT");
                        exit(0);
                        break;
                default:printf("\n invalid entry...try again");
            }
            //enqueue(10);
            //enqueue(20);
            //enqueue(30);
            // Display the queue


            // Dequeue an element and print it

            // Display the queue again

    }while(ch!=7);	
    
    return 0;
}
