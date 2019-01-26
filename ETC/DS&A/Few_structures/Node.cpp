#include <iostream>

using namespace std;

struct Node 
{
	int data;
	Node* prev;
	Node* next;
	
	Node(int aData, Node* aPrev, Node* aNext)
	: data(aData), prev(aPrev), next(aNext)
	{}
};

void pushBack(Node*& head, Node*& tail, int x)
{
	if(head == nullptr)
	{
		head = tail = new Node (x, nullptr, nullptr);
	}
	else 
	{
		tail->next = new Node(x, tail, nullptr);
		tail = tail->next;
	}
}
void printInDirOrder(Node*& head, Node*& tail)
{
	for (Node* p = head; p != nullptr; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}
void printInRevOrder(Node*& head, Node*& tail)
{
	for (Node* p = tail; p != nullptr; p = p->prev) {
		cout << p->data << " ";
	}
	cout << endl;
}
void insertBefore(Node*& head, Node* curr, int elem)
{
	if(head == curr) 
	{
		head->prev = new Node(elem, nullptr, head);
		head = head->prev;
	}
	else
	{
		curr->prev->next = new Node(elem, curr->prev, curr);
		curr->prev = curr->prev->next;
	}
}
Node* erase(Node*& head, Node*& tail, Node* curr)
{
	if(head == curr && head == tail) 
	{
		delete curr;
		return nullptr;
	}
	if(head == curr)
	{
		Node* t = head->next;
		delete head;
		head = t;
		head->prev = nullptr;
		return head;	
	}
	if(tail == curr) 
	{
		Node* t = tail->prev;
		delete tail;
		tail = t;
		tail->next = nullptr;
		return nullptr;
	}
	else 
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		Node* t = curr->next;
		delete curr;
		return t;
	}
}
int main() 
{
	Node* head = nullptr;
	Node* tail = nullptr;
	
	int x;
    while (cin >> x)
    {
        pushBack(head, tail, x);
    }
	printInDirOrder(head, tail);
    printInRevOrder(head, tail);
	
	for (Node* p = head; p != nullptr; p = p->next) 
	{
		if(p->data % 2 == 0) {
			insertBefore(head, p, 0);
		}
	}
	printInDirOrder(head, tail);
    printInRevOrder(head, tail);
	
	Node* p = head;
	while (p != nullptr)
    {
        if (p->data % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->next;
        }
    }
	printInDirOrder(head, tail);
    printInRevOrder(head, tail);
	return 0;
}