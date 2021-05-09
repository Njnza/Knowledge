#include <iostream>
#include "linkedList.h"
#include "BST.h"

Node_t* head = NULL;
BstNode_t* root = NULL;

int main()
{
	std::cout << "hello world" << std::endl;
	root = BST_Insert(root, { 2, 3 });
	root = BST_Insert(root, { 2, 3 });
	root = BST_Insert(root, { 4, 3 });
	root = BST_Insert(root, { 6, 3 });
	root = BST_Insert(root, { 1, 3 });
	root = BST_Insert(root, { 5, 3 });
	
	std::cout << "height: " << BST_Find_height(root) << std::endl;

	BST_Preorder(root);

	BST_Delete(root, { 2, 0 });
	//BST_Delete(root, { 6, 0 });
	BST_Delete(root, { 7, 1 });

	std::cout << std::endl;
	BST_Inorder(root);

	std::cout << std::endl << "Contain: " << BST_Is_contain(root, {6, 0});

	return 0;
}