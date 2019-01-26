#ifndef HASHSETSTR_H
#define HASHSETSTR_H

#include <string>
#include <vector>

class HashSetStr 
{
	private:
	
	struct Node {
		
		std::string data;
		Node* next;
		
		Node(const std::string& d, Node* n) 
		: data(d), next(n)
		{}
	};
	
	std::vector<Node*> buckets;
	std::size_t length;
	HashFunction hashF;
	
	
	public:
	
	typedef std::size_t (*HashFunction)(const std::string& s);
	
	HashSetStr(HashFunction hf)
	: buckets(2, nullptr), length(0), hashF(hf)
	{
		
	}
	
	HashSetStr(const HashSetStr& other) = delete;
	HashSetStr& operator=(const HashSetStr& other) = delete;
	
	
	~HashSetStr()
	{
		clear();
	}
	
	size_t bucketCount() const 
	{
		return buckets.size();
	}
	
	HashFunction getHashFunction() const 
	{
		return hashF;
	}
	
	
	
	
	bool find(const std::string& s) const;
	bool insert(const std::string& s);
	bool erase(const std::string& s);
	void rehash(size_t newSize);
	
	void print() const;
	void clear();
};
#endif