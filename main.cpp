#include "AVLTree.h"
#include <chrono>
#include <algorithm>
#include <random>
#include <array>

int main() {
	//case 1
	AvlTree<int> tree1;
	AvlTree<int> tree2;
	AvlTree<int> tree3;
	for (int i = 1; i < 100; i++) {
		
		tree1.insert(tree1.root, i);
		i++;
	}
	for (int i = 99; i > 0; i--) {
		
		tree2.insert(tree2.root, i);
		i--;
	}
	int arr3[50];
	for (int i = 0; i < 50; i++) {
		arr3[i] = i*2+1;
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(arr3, arr3+50, std::default_random_engine(seed));
	for (int i = 0; i < 50; i++) {
		tree3.insert(tree3.root, arr3[i]);
	}
	
	std::cout << "(Acending, Decending, Random)\nHeight Test:\n" << tree1.height(tree1.root) << "\n" << tree2.height(tree2.root) << "\n" << tree3.height(tree3.root) << "\n\n";
	std::cout << "Validate Test:\n" << tree1.validate() << " " << tree2.validate() << " " << tree3.validate();
	std::cout << "\nContains Test:\n";
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			if (tree1.contains(i) == 1 || tree2.contains(i) == 1 || tree3.contains(i) == 1) {
				std::cout << "My AVL tree implementation is wrong";
			}
		}
	}
}