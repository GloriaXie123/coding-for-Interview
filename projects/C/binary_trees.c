/*
In this problem, we continue our study of binary trees. 
Let the nodes in the tree have the following structure.

struct tnode
{
	int data;
	int tnode *left;
	int tnode *right;	
}
Use the Template in the Lec06 to add element to the list.
Write a function struct tnode *talloc(int data) that allocates a new node with the given data.
Complete the function addnode() by filling in the missing section. Insert the elements 3,1,0,2,8,6,5,9
in the same order.
Write function void preorder(struct tnode *root) to display the elements in pre-order travesal.
Write function void inorder(struct tnode *root) to display the elements in in-order travesal.
Write function int deltree(struct tnode *root) to delete all the elements of the tree. the function 
must return the number of tnodes deleted. make sure not to use any pointer after it has been freed(
Hint: use post-order travesal).
Write the test code to illustrate the working of each of the above functions.
*/
struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};

/*write the function struct tnode *talloc(int data) that allocates a new node with the given data*/
/*
@function talloc
@desc allocates a new tree node
@param [IN] data: the data to be inserted into the treenode
@returns pointer to the new tree node or NULL upon failure
*/
struct tnode *talloc(int data)
{
	struct tnode *p = (struct tnode *)malloc(sizeof(struct tnode));
	if (p != NULL)
	{
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

/*complete the function addnode() by filling in the missing section*/
struct tnode *addnode(struct tnode *root, int data)
{
	if (root == NULL)
	{
		root = talloc(data);
		return root;
	}
	else
	{
		if (data < root->data)
		{
			root->left = addnode(root->left, data);
		}
		else
		{
			root->right = addnode(root->right, data);
		}
	}
}

/*Write the function void preorder(struct tnode* root) to display the elements using pre-order
travesal:
preorder: root, left subtree, right subtree*/

void preorder(struct tnode *root)
{
	struct tnode *p = NULL;
	p = root;
	while (root != NULL)
	{
		printf("%d\t", root->data);
		root = root->left;
	}

	root = p->right;
	while (root != NULL)
	{

		printf("%d\t", root->data);
		root = root->right;
	}
}

/*
@func preorder
@desc display elements in preorder
@param [IN] the root of the tree
@returns nothing*/
void preorder(struct tnode *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

/*Write function void inorder(struct tnode *root) to display elements
using in-order traversal, Note that the elements are sorted.*/
/*
@func inorder
@desc display elements using in-order traversal
@param [IN] root node of the tree
@returns nothing
*/
void inorder(struct tnode *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

/*Write function int deltree(struct tnode *root) to delete all the elements of the tree,
the function must return the number of nodes deleted,
make sure not to use any pointer after it has been freed.(Hint: using post-order
(left subtree, right subtree ,root) traversal)*/
int deltree(struct tnode *root)
{
	int delnum = 0;
	if (root == NULL)
		return;
	delnum += deltree(root->left);
	delnum += deltree(root->right);
	free(root);
	return delnum++;
}

/*write test code to illustrate the work of each of the above functions.*/
int main()
{
	struct tnode *root = NULL;
	int count = 0;
	/*test addnode*/
	addnode(root, 3);
	addnode(root, 1);
	addnode(root, 0);
	addnode(root, 2);
	addnode(root, 8);
	addnode(root, 6);
	addnode(root, 5);
	addnode(root, 9);

	/*preorder*/
	preorder(root);
	puts("The list should be: 3 1 0 2 8 6 5 9;");

	/*inorder*/
	inorder(root);
	puts("The list should be: 0 1 2 3 5 6 8 9;");

	/*test deltree*/
	count = deltree(root);
	puts("should expect 8 nodes deleted");
	printf("%d nodes deleted\n", count);
}
