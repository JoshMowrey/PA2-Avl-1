#pragma once
#include <iostream>

template <typename T>
class  AvlNode {
public:
	AvlNode(T data);
	~AvlNode();
	AvlNode* pLeft;
	AvlNode* pRight;
	T data;
	int height;
};


template<typename T>
inline AvlNode<T>::AvlNode(T data)
{
	this->data = data;
	this->height = 1;
	pLeft = nullptr;
	pRight = nullptr;
}

template<typename T>
inline AvlNode<T>::~AvlNode()
{
	if (pLeft != nullptr) {
		delete pLeft;
	}
	if (pRight != nullptr) {
		delete pRight;
	}
}
