#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left,*right;
};

struct node* create(struct node* root) {
    struct node* newnode, * temp, * parent;
    int i, n, num;
    printf("Enter how many numbers do you want!\n");
    scanf("%d", &n);
    printf("Enter %d nodes in tree:\n",n);
    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        if (root == NULL) {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL) {
            parent = temp;
            if (num < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (num < parent->data) {
            parent->left = newnode;
        }
        else {
            parent->right = newnode;
        }
    }
    return root;
}
void inorder(struct node*root)
{
	struct node*temp=root;
	if(temp == NULL)
	{
		return ;
	}

	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);
}
void insert(struct node*root,int key)
{
	struct node*prev;
	while(root != NULL)
	{
		prev=root;
		if(root->data == key)
		{
			printf("Cannot insert data\n");
			return;
		}
		else if(root->data >key)
		{
			root=root->left;
		}
		else{
			root=root->right;
		}
	}
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=newnode->right=NULL;
	newnode->data=key;
	if(prev->data > key)
	{
		prev->left=newnode;
	}
	else{
		prev->right=newnode;
	}
}

struct node* prev(struct node* root) {
    struct node* temp = root->left;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

struct node* dlt(struct node* root, int key) {
    struct node* ipre;

    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    if (key < root->data) {
        root->left = dlt(root->left, key);
    } else if (key > root->data) {
        root->right = dlt(root->right, key);
    } else {
        ipre = prev(root);
        root->data = ipre->data;
        root->left = dlt(root->left, ipre->data);
    }

    return root;
}
void main()
{
	struct node*root,*temp;
	int ch,x,i;
	do
	{
		printf("\n\n-----------MENU-------------\n\n");
		printf("\n1.create\n2.insert\n3.inorder\n4.delete\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=NULL;
				root=create(root);
				break;
			case 2:
				printf("\nEnter data to insert in BST:");
				scanf("%d",&x);
				insert(root,x);
				break;
			case 3:
				printf("\nInorder trevrece:\n");
				inorder(root);
				break;
			case 4:
				printf("\nEnter element to delete in tree:\n");
				scanf("%d",&x);
				temp=dlt(root,x);
				if(temp!= NULL){
					printf("\n%d Element is succesfully delete:\n",x);
				}
				else{
					printf("\n%d Element is not found in tree:\n",x);
				}
				break;
			default:
				printf("\nHEY YOU HAVE NOT INSERT CORRECT OPTION PLEACE TRY AGAIN!\n");
		}
	}while(ch !=5);
}
		
		
		
		
