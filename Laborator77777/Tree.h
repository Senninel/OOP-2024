#pragma once
#include <iostream>

template <typename T>
int compara(T firstvalue, T secondvalue)
{
	if (firstvalue < secondvalue)
	{
		return -1;
	}
	else if (firstvalue > secondvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
int compara2(T firstvalue, T secondvalue)
{
	if (firstvalue > secondvalue)
	{
		return -1;
	}
	else if (firstvalue < secondvalue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
struct Node
{
	T value;
	Node** children;
	unsigned int nrChildren;
};

template <class T>
class Tree
{

public:
	Node<T>* root;
	unsigned int MaxnrChildren;
	
	Tree(unsigned int nrChildren)
	{
		this->MaxnrChildren = nrChildren;
		root = nullptr;
	}

	void add_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T> *[MaxnrChildren] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<T>;
			parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T> *[MaxnrChildren] {};
			parent->nrChildren++;
		}
	}


	void PrintChildren(Node<T>* parent)
	{
		unsigned int i;
		for (i = 0;i < parent->nrChildren;i++)
		{
			std::cout << parent->children[i]->value << " ";
		}
	}

	void sort(Node<T>* parent, int (*compara)(T, T))
	{
		unsigned int i, j;
		for (i = 0;i < parent->nrChildren - 1;i++)
		{
			for (j = i + 1;j < parent->nrChildren;j++)
			{
				if (compara(parent->children[i]->value, parent->children[j]->value) == 1)
				{
					T aux = parent->children[i]->value;
					parent->children[i]->value = parent->children[j]->value;
					parent->children[j]->value = aux;
				}
			}
		}
	}

	Node<T>* findParentNode(Node<T>* parent, Node<T>** curent)
	{
		if (*curent == nullptr || *curent == root)
		{
			return root;
		}
		
		Node<T>* kid = (*curent)->children[0];
		while (kid)
		{
			if (kid == parent)
			{
				return parent;
			}
			Node<T>* result = findParentNode(parent, &kid);
			if (result)
			{
				return result;
			}
		}
		return nullptr;
	}

	Node<T>* GetNode(Node<T>* parent)
	{
		return findParentNode(parent, &root);
	}

	void deleteNode(Node<T>* nodeTodelete)
	{
		if (!nodeTodelete) return;
		
		Node<T>* parent = nullptr;
		if (nodeTodelete != root)
		{
			parent = findParentNode(nodeTodelete, &root);
			if (!parent) return;
		}
		if (parent)
		{
			unsigned int i = 0;
			
			while (parent->children[i] != nodeTodelete && i < parent->nrChildren)
			{
				++i;
			}
			if (i < parent->nrChildren)
			{
				deleteSubTree(nodeTodelete);
				for (unsigned int j = i; j < parent->nrChildren - 1; j++)
				{
					parent->children[j] = parent->children[j + 1];
				}
				parent->children[parent->nrChildren - 1] = nullptr;
				parent->nrChildren--;
			}
		}
		else
		{
			deleteSubTree(root);
			root = nullptr;
		}
	}

	void deleteSubTree(Node<T>* node)
	{
		if (!node)
		{
			return;
		}

		for (unsigned int i = 0; i < node->nrChildren;i++)
		{
			deleteSubTree(node->children[i]);
		}
		delete[] node->children;
		delete node;
	}

	Node<T>* findNode(Node<T>* node, bool(*compara)(T, T), T target)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (compara(node->value, target))
		{
			return node;
		}
        
		for (unsigned int i = 0; i < node->nrChildren; i++)
		{
			Node<T>* found = findNode(node->children[i], compara, target);
			if (found != nullptr)
			{
				return found;
			}
		}
		return nullptr;
	}

	void insert(Node<T>* parent, unsigned int index, T value)
	{
		if (parent == nullptr || index > parent->nrChildren)
		{
			std::cout << "Parinte sau index invalid" << std::endl;
		}

		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		newNode->nrChildren = 0;
		newNode->children = new Node<T>*[MaxnrChildren] {};

		for (unsigned int i = parent->nrChildren;i > index;i--)
		{
			parent->children[i] = parent->children[i - 1];
		}
		parent->children[index] = newNode;
		parent->nrChildren++;
	}

	void PrintTree(Node<T>* node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}

		for (unsigned int i = 0;i < depth;i++)
		{
			std::cout << "  ";
		}
		std::cout << node->value << std::endl;

		for (unsigned int i = 0;i < node->nrChildren;i++)
		{
			PrintTree(node->children[i], depth + 1);
		}
	}

	int count(Node<T>* parent)
	{
		if (parent == nullptr)
		{
			return root->nrChildren;
		}
		return parent->nrChildren;
	}
};



template<>
class Tree<char*>
{
public:
	Node<char*>* root;
	unsigned int MaxnrChildren;

	Tree(unsigned int nrChildren)
	{
		this->MaxnrChildren = nrChildren;
		root = nullptr;
	}

	void add_node(Node<char*>* parent,  char* value)
	{
		if (parent == nullptr)
		{
			root = new Node<char*>;
			root->value = new char[strlen(value) +1];
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*> *[MaxnrChildren] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<char*>;
			parent->children[parent->nrChildren]->value = new char[strlen(value) + 1];
			strcpy(parent->children[parent->nrChildren]->value, value);
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<char*> *[MaxnrChildren] {};
			parent->nrChildren++;
		}
	}


	void PrintChildren(Node<char*>* parent)
	{
		unsigned int i;
		for (i = 0;i < parent->nrChildren;i++)
		{
			std::cout << parent->children[i]->value << " ";
		}
	}

	void sort(Node<char*>* parent, int (*compara)(char*, char*))
	{
		unsigned int i, j;
		for (i = 0;i < parent->nrChildren - 1;i++)
		{
			for (j = i + 1;j < parent->nrChildren;j++)
			{
				if (strcmp(parent->children[i]->value, parent->children[j]->value) > 0)
				{
					char* aux = parent->children[i]->value;
					parent->children[i]->value = parent->children[j]->value;
					parent->children[j]->value = aux;
				}
			}
		}
	}

	Node<char*>* findParentNode(Node<char*>* parent, Node<char*>** curent)
	{
		if (*curent == nullptr || *curent == root)
		{
			return root;
		}

		Node<char*>* kid = (*curent)->children[0];
		while (kid)
		{
			if (kid == parent)
			{
				return parent;
			}
			Node<char*>* result = findParentNode(parent, &kid);
			if (result)
			{
				return result;
			}
		}
		return nullptr;
	}

	Node<char*>* GetNode(Node<char*>* parent)
	{
		return findParentNode(parent, &root);
	}

	void deleteNode(Node<char*>* nodeTodelete)
	{
		if (!nodeTodelete) return;

		Node<char*>* parent = nullptr;
		if (nodeTodelete != root)
		{
			parent = findParentNode(nodeTodelete, &root);
			if (!parent) return;
		}
		if (parent)
		{
			unsigned int i = 0;

			while (parent->children[i] != nodeTodelete && i < parent->nrChildren)
			{
				++i;
			}
			if (i < parent->nrChildren)
			{
				deleteSubTree(nodeTodelete);
				for (unsigned int j = i; j < parent->nrChildren - 1; j++)
				{
					parent->children[j] = parent->children[j + 1];
				}
				parent->children[parent->nrChildren - 1] = nullptr;
				parent->nrChildren--;
			}
		}
		else
		{
			deleteSubTree(root);
			root = nullptr;
		}
	}

	void deleteSubTree(Node<char*>* node)
	{
		if (!node)
		{
			return;
		}

		for (unsigned int i = 0; i < node->nrChildren;i++)
		{
			deleteSubTree(node->children[i]);
		}
		delete[] node->children;
		delete node;
	}

	Node<char*>* findNode(Node<char*>* node, bool(*compara)(char*, char*), char* target)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (compara(node->value, target))
		{
			return node;
		}

		for (unsigned int i = 0; i < node->nrChildren; i++)
		{
			Node<char*>* found = findNode(node->children[i], compara, target);
			if (found != nullptr)
			{
				return found;
			}
		}
		return nullptr;
	}

	void insert(Node<char*>* parent, unsigned int index, char *value)
	{
		if (parent == nullptr || index > parent->nrChildren)
		{
			std::cout << "Parinte sau index invalid" << std::endl;
		}

		Node<char*>* newNode = new Node<char*>;
		newNode->value = value;
		newNode->nrChildren = 0;
		newNode->children = new Node<char*>*[MaxnrChildren] {};

		for (unsigned int i = parent->nrChildren;i > index;i--)
		{
			parent->children[i] = parent->children[i - 1];
		}
		parent->children[index] = newNode;
		parent->nrChildren++;
	}

	void PrintTree(Node<char*>* node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}

		for (unsigned int i = 0;i < depth;i++)
		{
			std::cout << "  ";
		}
		std::cout << node->value << std::endl;

		for (unsigned int i = 0;i < node->nrChildren;i++)
		{
			PrintTree(node->children[i], depth + 1);
		}
	}

	int count(Node<char*>* parent)
	{
		if (parent == nullptr)
		{
			return root->nrChildren;
		}
		return parent->nrChildren;
	}
};