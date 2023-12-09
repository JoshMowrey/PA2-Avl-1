#pragma once
#include "AVLNode.h"

template <typename T>
class AvlTree {
public:
	AvlTree();
	~AvlTree();
	int height(AvlNode<T>* cNode) {
		if (cNode == nullptr) {
			return 0;
		}
		return cNode->height;
	}
	void insert(AvlNode<T>* &cNode, T data);
	void printInorder(struct AvlNode<T>* node)
	{
		if (node == NULL) {
			return;
		}
		printInorder(node->pLeft);
		std::cout << node->data << ": " << node-> height << " " ;
		printInorder(node->pRight);
	}
	int checkBalance(AvlNode<T>* cNode);
	int contains(T data);
	int validate();
	int contains(T data, AvlNode<T>* cNode) {
		if (cNode->data == data) {
			return 1;
		}
		else if (cNode->data > data) {
			if (cNode->pLeft == nullptr) {
				return 0;
			}
			return contains(data, cNode->pLeft);
		}
		else if (cNode->data < data) {
			if (cNode->pRight == nullptr) {
				return 0;
			}
			return contains(data, cNode->pRight);
		}
	}
	AvlNode<T>* root;
	AvlNode<T>* leftRotate (AvlNode<T>* cNode) {
		AvlNode<T>* cRight = cNode->pRight;
		AvlNode<T>* CRLeft = cRight->pLeft;

		cRight->pLeft = cNode;
		cNode->pRight = CRLeft;
		

		if (height(cNode->pLeft) < height(cNode->pRight)) {
			cNode->height = height(cNode->pRight) + 1;
		}
		else {
			cNode->height = height(cNode->pLeft) + 1;
		}
		if (height(cRight->pLeft) < height(cRight->pRight)) {
			cRight->height = height(cRight->pRight) + 1;
		}
		else {
			cRight->height = height(cRight->pLeft) + 1;
		}
		return cRight;
	}
	AvlNode<T>* rightRotate(AvlNode<T>* cNode) {
		AvlNode<T>* cLeft = cNode->pLeft;
		AvlNode<T>* CLRight = cLeft->pRight;

		cLeft->pRight = cNode;
		cNode->pLeft = CLRight;
		
		
		if (height(cNode->pLeft) < height(cNode->pRight)) {
			cNode->height = height(cNode->pRight) + 1;
		}
		else {
			cNode->height = height(cNode->pLeft) + 1;
		}
		if (height(cLeft->pLeft) < height(cLeft->pRight)) {
			cLeft->height = height(cLeft->pRight) + 1;
		}
		else {
			cLeft->height = height(cLeft->pLeft) + 1;
		}

		return cLeft;
		
	}
};


template<typename T>
inline AvlTree<T>::AvlTree(){
	root = nullptr;
}

template<typename T>
inline AvlTree<T>::~AvlTree()
{
	delete root;
}
template<typename T>
inline void AvlTree<T>::insert(AvlNode<T>* &cNode, T data)
{
	if (cNode == nullptr) {
		cNode = new AvlNode<T>(data);
		return;
	}
	else if (data > cNode->data) { //insert Right
		insert(cNode->pRight, data);
		cNode->height = cNode->pRight->height + 1;
	}
	else if (data < cNode->data) { //insert Left
		insert(cNode->pLeft, data);
		cNode->height = cNode->pLeft->height + 1;
	}
	

	if (checkBalance(cNode) > 1 && data < cNode->pLeft->data) {
		cNode = rightRotate(cNode);
	}

	if (checkBalance(cNode) < -1 && data > cNode->pRight->data) {
		cNode = leftRotate(cNode);
	}
 
	if (checkBalance(cNode) > 1 && data > cNode->pLeft->data){
		cNode->pLeft = leftRotate(cNode->pLeft);
		cNode = rightRotate(cNode);
	}

	if (checkBalance(cNode) < -1 && data < cNode->pRight->data){
		cNode->pRight = rightRotate(cNode->pRight);
		cNode = leftRotate(cNode);
	}
}

template<typename T>
inline int AvlTree<T>::checkBalance(AvlNode<T>* cNode)
{
	if (cNode == nullptr) {
		return 0;
	}
	return height(cNode->pLeft) - height(cNode->pRight);
}

template<typename T>
inline int AvlTree<T>::contains(T data)
{
	if (root->data == data) {
		return 1;
	}
	else if (root->data > data) {
		if (root->pLeft == nullptr) {
			return 0;
		}
		return contains(data, root->pLeft);
	}
	else if (root->data < data) {
		if (root->pRight == nullptr) {
			return 0;
		}
		return contains(data, root->pRight);
	}
}

template<typename T>
inline int AvlTree<T>::validate()
{
	if (root->pLeft->height > (root->pRight->height) + 1 || root->pRight->height > (root->pLeft->height)+1) {
		return 0;
	}
	else {
		return 1;
	}
}

