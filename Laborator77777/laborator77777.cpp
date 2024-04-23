#include <iostream>
#include "Tree.h"
int main()
{
	Tree<int> copac(4);
	
	Node<int>* node1 = nullptr;
	Node<int>* node2 = nullptr;
	Node<int>* node3 = nullptr;

	copac.add_node(nullptr, 10);
	copac.add_node(copac.root, 20);
	copac.add_node(copac.root, 30);
	copac.add_node(copac.root, 40);

	node1 = copac.root->children[0];
	node2 = copac.root->children[1];
	node3 = copac.root->children[2];

	copac.add_node(node1, 15);
	copac.add_node(node1, 25);

	copac.add_node(node2, 35);
	copac.add_node(node2, 45);

	copac.add_node(node3, 55);
	copac.add_node(node3, 65);

	copac.PrintTree(copac.root);
	std::cout << "\n\n";

	copac.sort(copac.root,compara);
	copac.PrintTree(copac.root);

	std::cout << "\n\n";
	copac.deleteNode(node1);
	copac.PrintTree(copac.root);

	std::cout << "\n\n";
	std::cout << "\n\n";

	Tree<char> arbore(10);
	arbore.add_node(nullptr, 'A');
	arbore.add_node(arbore.root, 'B');
	arbore.add_node(arbore.root, 'C');
	arbore.add_node(arbore.root->children[0], 'D');
	arbore.add_node(arbore.root->children[0], 'E');
	arbore.add_node(arbore.root->children[1], 'F');
	arbore.add_node(arbore.root->children[1], 'G');

	arbore.PrintTree(arbore.root);


}
	