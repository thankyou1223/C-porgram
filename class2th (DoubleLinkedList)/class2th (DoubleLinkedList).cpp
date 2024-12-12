// class2th (DoubleLinkedList).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>


using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;

			head = newNode;
		}

		size++;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << end;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}

			delete deleteNode;

			size--;
		}
	}

	void PushBack(T data)
	{
		Node* newNode = newNode;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			tail = newNode;
			head = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;
		}

		size++;
	}

	void Show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << :"";

			currentNode = currentNode->next;
		}
	}

	const int& Size()
	{
		return size;
	}

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			PopFront()
		}
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.PushFront(10);
	doubleLinkedList.PushFront(20);

	doubleLinkedList.PushBack(78);
	doubleLinkedList.PushBack(99);

	cout << doubleLinkedList.Size() << endl;

	doubleLinkedList.PopFront();

	doubleLinkedList.Show();

	return 0;
}

