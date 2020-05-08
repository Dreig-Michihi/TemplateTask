// TemplateTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include "Stack.h"
using namespace std;

template<typename T>
class Stack
{
protected:
	class Node {
	public:
		Node *pNext;
		T data;
		Node() :data(T()), pNext(nullptr) {}
		Node(T data) :data(data), pNext(nullptr) {}
		Node(T data, Node *pNext) :data(data), pNext(pNext) {}
	};
	int Size;
	Node* head;
public:
	//конструктор по-умолчанию
	Stack() :Size(0), head(nullptr) {}
	//копирование
	Stack(Stack& obj) {
		if (this->Size > 0)
			this->clear();
		Node* temp = obj.head;
		T* tempArray = new T [obj.Size];
		int i = obj.Size-1;
		while (temp != nullptr) {
			tempArray[i] = temp->data;
			i--;
			temp = temp->pNext;
		}
		for(int i=0;i<obj.Size;i++)
			this->push(tempArray[i]);
	}
	//деструктор
	~Stack() {
		if (this->Size > 0)
			this->clear();
	}

	int getSize() { return Size; }

	void push(T data) {
		try {
			if (head != nullptr) {
				Node* temp = new Node(data, head);//создаётся новый элемент ссылающийся на текущий head
				head = temp;//добавленный элемент становится новым head'ом
			}
			else {
				head = new Node(data);//стек был пуст, поэтому создаётся первый элемент, ссылающийся на nullptr, и становится head'ом
			}
			Size++;
		}
		catch (bad_alloc) {
			cout << "Невозможно добавить новый элемент, так как стек переполнен." << endl;
		}
	}
	void pop() {
		try
		{
			if (head == nullptr)
				throw out_of_range("Стек пуст! Error: out of range\n");
			Node* temp = head;
			head = head->pNext;
			delete temp;
			Size--;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	T& top() {
		try
		{
			if (head == nullptr)
				throw out_of_range("Стек пуст! Error: out of range\n");
			return head->data;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	void print() {
		try
		{
			if (head == nullptr)
				throw out_of_range("Стек пуст! Error: out of range\n");
			Stack <T> temp = *this;
			while (temp.Size > 0) {
				cout << temp.top() << endl;
				temp.pop();
			}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	void clear() {
		try
		{
			if (head == nullptr)
				throw out_of_range("Стек пуст! Error: out of range\n");
			while (Size > 0)
				this->pop();
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
};

int main()
{
	setlocale(0, "ru");
	Stack<double> st1;
	st1.push(1);
	st1.push(2);
	st1.push(2);
	st1.push(4);
	st1.push(5);
	Stack<double> st2=st1;
	st1.push(3);
	st1.push(12);
	st1.push(30);
	cout << "st1:\n";
	st1.print();
	cout << "st2:\n";
	st2.print();
	st1.pop();
	st1.pop();
	st1.pop();
	st1.pop();
	cout << "st1:\n";
	st1.print();
	cout << "st1.top():\n" << st1.top();
	return 0;
}
