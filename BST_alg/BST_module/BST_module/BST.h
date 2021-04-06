#pragma once
#include <stdint.h>
#include <iostream>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct data
{
	//uint16_t number[100];
	uint16_t key;
	uint16_t index;

} data_t;

typedef struct BstNode
{
	data_t _data;
	struct BstNode* _right;
	struct BstNode* _left;

} BstNode_t;

				/* DEFINE FUNCTIONS */
BstNode_t*		BST_New_node(data_t data);
int16_t			BST_Find_height(BstNode_t* root);
BstNode_t*		BST_Insert(BstNode_t* root, data_t data);
BstNode_t*		BST_Delete(BstNode_t* root, data_t data);
BstNode_t*		BST_Search(BstNode_t* root, data_t data);
bool			BST_Is_contain(BstNode_t* root, data_t data);
int8_t			BST_Compare(data_t const* src, data_t const* dst);
void			BST_Preorder(BstNode_t* root);
BstNode_t*		BST_Find_min(BstNode_t* root);
BstNode_t*		BST_Find_max(BstNode_t* root);


				/* Implement Functions*/
BstNode_t* BST_New_node(data_t data)
{
	BstNode_t* newNode = (BstNode_t*)malloc(sizeof (BstNode_t));
	newNode->_data = data;
	newNode->_left = NULL;
	newNode->_right = NULL;

	return newNode;
}

int16_t BST_Find_height(BstNode_t* root)
{
	if (root == NULL)
	{
		return -1;
	}

	int16_t leftHeight = BST_Find_height(root->_left);
	int16_t rightHeight = BST_Find_height(root->_right);

	return (int16_t)MAX(leftHeight, rightHeight) + 1;
}

BstNode_t* BST_Insert(BstNode_t* root, data_t data)
{
	if (root == NULL)									// empty tree
	{
		root = BST_New_node(data);
	}
	else if (BST_Compare(&data, &root->_data) != 1)		// insert to left root
	{
		root->_left = BST_Insert(root->_left, data);
	}
	else												// Insert to right root
	{
		root->_right = BST_Insert(root->_right, data);
	}

	return root;
}

BstNode_t* BST_Delete(BstNode_t* root, data_t data)
{
	if (root == NULL) { 
		std::cout << std::endl << "DELETE FALSE: " << data.key << std::endl;
		return root; 
	}
	else if (BST_Compare (&data, &root->_data) == (-1))
	{
		root->_left = BST_Delete(root->_left, data);
	}
	else if (BST_Compare(&data, &root->_data) == 1)
	{
		root->_right = BST_Delete(root->_right, data);
	}
	else
	{
		// Case 1: No child
		if (root->_left == NULL && root->_right == NULL)
		{
			free(root);
			root = NULL;
		}
		// Case 2: One Child
		else if (root->_left == NULL)
		{
			BstNode_t* temp = root;
			root = root->_right;
			free(temp);
		}
		else if (root->_right == NULL)
		{
			BstNode_t* temp = root;
			root = root->_left;
			free(temp);
		}
		// Case 3: 2 child
		else
		{
			BstNode_t* temp = BST_Find_min(root->_right);
			root->_data = temp->_data;
			root->_right = BST_Delete(root->_right, temp->_data);
		}
	}

	return root;
}

BstNode_t* BST_Search(BstNode_t* root, data_t data)
{
	if (root == NULL) { return NULL; }

	if (BST_Compare(&data, &root->_data) == 1)
	{
		return BST_Search(root->_right, data);
	}
	else if (BST_Compare(&data, &root->_data) == -1)
	{
		return BST_Search(root->_left, data);
	}

	return root;
}

bool BST_Is_contain(BstNode_t* root, data_t data)
{
	if (BST_Search (root, data) != NULL)
	{
		return true;
	}

	return false;
}

int8_t BST_Compare(data_t const* src, data_t const* dst)
{
	if (src->key == dst->key)
	{
		return 0; // src equal dst
	}
	else if (src->key > dst->key)
	{
		return 1; // src biger dst
	}

	return -1; // src smaller dst
}

void BST_Preorder(BstNode_t* root)	// root, left, right
{
	if (root == NULL) { return; }

	std::cout << root->_data.key << " ";
	BST_Preorder(root->_left);
	BST_Preorder(root->_right);
}

void BST_Inorder(BstNode_t* root)	// left, root, right
{
	if (root == NULL) { return; }

	BST_Inorder(root->_left);
	std::cout << root->_data.key << " ";
	BST_Inorder(root->_right);
}

void BST_Postorder(BstNode_t* root)	// left, right, root
{
	if (root == NULL) { return; }

	BST_Postorder(root->_left);
	BST_Postorder(root->_right);
	std::cout << root->_data.key << " ";
}

BstNode_t* BST_Find_min(BstNode_t* root)
{
	if (root == NULL) { return false; }
	else if (root->_left == NULL) { return root; }
	return BST_Find_min (root->_left);
}

BstNode_t* BST_Find_max(BstNode_t* root)
{
	if (root == NULL) { return false; }
	else if (root->_right == NULL) { return root; }
	return BST_Find_max (root->_right);
}