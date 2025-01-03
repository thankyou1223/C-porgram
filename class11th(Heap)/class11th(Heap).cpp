﻿// class11th(Heap).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#define SIZE 8

using namespace std;

template <typename T>
class Heap
{
private:
	int index;

	T container[SIZE];
public:
	Heap()
	{
		index = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (index + 1 >= SIZE)
		{
			cout << "Heap Overflow" << endl;
		}
		else
		{
			container[++index] = data;

			int child = index;
			int parent = child / 2;

			while (child > 1)
			{
				if (container[parent] < container[child])
				{
					std::swap(container[parent], container[child]);
				}

				child = parent;
				parent = child / 2;
			}
		}
	}

	const T& Remove()
	{
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;

			exit(0);
		}

		T result = container[1];

		container[1] = container[index];

		container[index--] = NULL;

		int parent = 1;

		while (parent * 2 <= index)
		{
			int child = parent * 2;

			if (container[child] < container[child + 1])
			{
				child++;
			}

			if (container[child] < container[parent])
			{
				break;
			}
			else
			{
				std::swap(container[parent], container[child]);

				parent = child;
			}
		}

		return result;
	}

	void Show()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << container[i] << " ";
		}
	}
};

int main()
{
	Heap<int> heap;

	heap.Insert(12);
	heap.Insert(10);
	heap.Insert(22);
	heap.Insert(30);

	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;

	heap.Show();

	return 0;
}

