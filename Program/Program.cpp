
#include <iostream>

using namespace std;

template <typename T>
class CircleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

public:
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}

		size++;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
		}

		size++;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head->next;

			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				head-


