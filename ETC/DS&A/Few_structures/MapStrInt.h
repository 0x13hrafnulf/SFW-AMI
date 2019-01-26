#ifndef MAPSTRINT_H
#define MAPSTRINT_H

#include <string>
#include <utility>

class MapStrInt
{
	public:
	
	MapStrInt()
	: root(nullptr), length(0)
	{
		
	}
	~MapStrInt()
	{
		clear();
	}
	
	int& operator[](const std::string& k);
	
	int size() const
	{
		return length;
	}
	
	void clear();
	void printInOrder() const;
	
	bool erase(const std::string& k);
	bool insert(const std::string& k, int v);
	std::pair<bool, int> find(const std::string& k) const;
	
	
	
	private:
	struct Node
	{
		Node* left;
		Node* right;
		std::pair<string,int> data;
		
		Node(const std::string& k, int v, Node* aLeft, Node* aRight)
		: data(k, v), left(aLeft), right(aRight)
		{
		}
	};
	struct StackFrame
	{
		const Node* node;
		int count;
		
		StackFrame(Node* aNode, int aCount)
		: node(aNode), count(aCount)
		{
		}
	};
	
	void eraseLeaf(Node* curr, Node* pred, bool isLeft);
	void eraseNodeWithOneChild(Node* curr, Node* pred, bool isLeft);
	void eraseNodeWithTwoChildren(Node* p);
	
	Node* root;
	int length;
	
};

#endif