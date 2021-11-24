#pragma once

typedef struct Node
{
	int key;
	int value;
	Node* left;
	Node* right;
	int N; //以该节点位根的子数中的节点个数
};

class BSTree
{
public:
	int size()
	{
		return size(root_);
	}

	int get(int key)
	{
		return get(root_, key);
	}
	void put(int key, int value)
	{
		root_ = put(root_, key, value);

	}

	int Min()
	{
		return min_(root_)->key;
	}

	int Floor(int key)
	{
		Node* x = floor_(root_, key);
		if (x == nullptr) return 0;
		return x->key;
	}

	void deleteMin()
	{
		root_ = deleteMin_(root_);
	}

	void deleteNode(int key)
	{
		deleteNode_(root_, key);
	}

private:
	int size(Node* node)
	{
		if (node == nullptr) return 0;
		else return node->N;
	}

	int get(Node* node, int key)
	{
		if (node == nullptr) return 0;
		int cmp = compare_key(key, node->key);

		if (cmp < 0)
		{
			return get(node->left, key);
		}
		else if (cmp > 0)
		{
			return get(node->right, key);
		}
		else
		{
			return node->value;
		}
	}

	Node* put(Node* node, int key, int value)
	{
		if (node == nullptr)
		{
			Node* retNode = new Node;
			retNode->key = key;
			retNode->value = value;
			return retNode;
		}
		
		int cmp = compare_key(key, node->key);

		if (cmp < 0)
		{
			return put(node->left,key,value);
		}
		else if (cmp > 0)
		{
			return put(node->right, key, value);
		}
		else
		{
			node->value = value;
		}
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}

	Node* min_(Node* node)
	{
		if (node->left == nullptr) return node;
		return min_(node->right);
	}

	Node* floor_(Node* node,int key)
	{
		if (node == nullptr) return nullptr;
		
		int cmp = compare_key(key, node->key);

		if (cmp == 0)
		{
			return node;
		}
		else if (cmp < 0)
		{
			return floor_(node->left, key);
		}
		Node* t = floor_(node->right, key);
		if (t != nullptr)
		{
			return t;
		}
		else 
		{
			return node;
		}
	}
	int compare_key(int k1, int k2)
	{
		return k1 - k2;
	}

	Node* deleteMin_(Node* node)
	{
		if (node->left == nullptr) return node->right;
		node->left = deleteMin_(node->left);
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}

	Node* deleteNode_(Node* node, int key)
	{
		if (node == nullptr) return nullptr;
		int cmp = compare_key(key, node->key);
		if (cmp < 0)
		{
			node->left = deleteNode_(node->left, key);
		}
		else if (cmp > 0)
		{
			node->right = deleteNode_(node->right, key);
		}
		else
		{
			if (node->right == nullptr) return node->left;
			if (node->left == nullptr) return node->right;
			Node* t = node;
			node = min_(node->right);
			node->right = deleteMin_(node->right);
			node->left = t->left;
		}
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}

private:
	Node* root_;

};

