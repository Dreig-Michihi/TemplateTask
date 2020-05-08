#pragma once
#include <iostream>
using namespace std;

template<typename T>
class BinaryTree
{
protected:
	class Node
	{
	public:
		Node() :data(T()), left(nullptr), right(nullptr) {}
		Node(T data) :data(data), left(nullptr), right(nullptr) {}
		~Node() {}
		T data;
		Node* left;
		Node* right;
	};
	Node* Find(T Data) {
		try {
			Node* temp = this->root;
			bool done = false;
			if (size == 0) {//если дерево пусто, то элемент не может быть найден.
				return nullptr;
			}
			else
				while (temp != nullptr&&temp->data != Data) {
					if (Data < temp->data) {//поворот налево
						temp = temp->left;//перейти к левому потомку.
					}
					else {//поворот направо
						temp = temp->right;//перейти к левому потомку.
					}
				}
			return temp;//Если элемент найден, то будет возвращена ссылка на него, иначе - нуллптр
		}
		catch (const std::exception&e)
		{
			cout << "Произошла ошибка: " << e.what() << endl;
		}
	}
	void detour(Node* node) {//рекурсивный алгоритм
		Node* n = node;
		cout << n->data << endl;//вывод вершины
		if (n->left != nullptr) {
			n = n->left;
			detour(n);
		}
		n = node;
		if (n->right != nullptr) {
			n = n->right;
			detour(n);
		}
	}
	void lists(Node* node) {
		Node* n = node;
		if (n->left == nullptr&&n->right == nullptr)
			cout << n->data << endl;//вывод вершины
		if (n->left != nullptr) {
			n = n->left;
			lists(n);
		}
		n = node;
		if (n->right != nullptr) {
			n = n->right;
			lists(n);
		}
	}
	int size;
	Node* root;
public:
	bool is_Exist(T Data) {//проверка, существует ли элемент.
		if (Find(Data) == nullptr)
			return false;
		else
			return true;
	}
	BinaryTree() :root(nullptr), size(0) {}
	~BinaryTree() {}
	void Add(T);//добавить элемент
	void Delete(T);//удалить элемент
	void Detour();//обход вершин дерева
	void Lists();//список листьев
};
//реализация методов
template<typename T>
inline void BinaryTree<T>::Lists()
{
	cout << "Список листьев:\n";
	if (size > 0)
		lists(this->root);
	else
		cout << "Бинарное дерево пусто.";
}
template<typename T>
inline void BinaryTree<T>::Detour()
{
	cout << "Обход вершин дерева:\n";
	if (size > 0)
		detour(this->root);
	else
		cout << "Бинарное дерево пусто.";
}
template<typename T>
inline void BinaryTree<T>::Add(T Data)
{
	try {
		Node* temp = this->root;
		bool done = false;
		if (size == 0) {//если дерево пусто, то создаётся корень
			Node* list = new Node(Data);
			this->root = list;//теперь root указывает на корень.
		}
		else
			while (!done) {
				if (Data < temp->data) {//поворот налево
					if (temp->left == nullptr) {//если у узла нет левого потомка, то
						Node* list = new Node(Data);//создать указатель на новый лист
						temp->left = list;//добавить предку ссылку на этот лист
						done = true;//выйти из цикла
					}
					else {
						temp = temp->left;//иначе перейти к левому потомку.
					}
				}
				else {//поворот направо
					if (temp->right == nullptr) {//если у узла нет правого потомка, то
						Node* list = new Node(Data);//создать новый лист
						temp->right = list;//добавить предку ссылку на этот лист
						done = true;//выйти из цикла
					}
					else {
						temp = temp->right;//иначе перейти к правому потомку.
					}
				}
			}
		size++;
	}
	catch (const std::exception&e)
	{
		cout << "Произошла ошибка: " << e.what() << endl;
	}
}
template<typename T>
inline void BinaryTree<T>::Delete(T Data)
{
	try {
		if (is_Exist(Data)) {
			Node* del = this->root;
			Node* delP = del;
			bool delleft = false;
			int ivent = 0;
			while (!(del->data == Data)) {
				if (Data < del->data) {//поворот налево
					delP = del;
					del = del->left;//перейти к левому потомку.
					delleft = true;
				}
				else {//поворот направо
					delP = del;
					del = del->right;//перейти к правому потомку.
					delleft = false;
				}
			}
			if (del->left != nullptr)ivent++;
			if (del->right != nullptr)ivent++;
			switch (ivent)
			{
			case 0: {//Ситуация 0: удаляется лист(узел без потомков)
				delete del;
				if (delleft)
					delP->left = nullptr;
				else
					delP->right = nullptr;
				break;
			}
			case 1: {//Ситуация 1: удаляется узел с одним потомком
				Node* newson;
				if (del->left != nullptr)
					newson = del->left;
				else
					newson = del->right;
				delete del;
				if (delleft)
					delP->left = newson;
				else
					delP->right = newson;
				break;
			}
			case 2: {//Ситуация 2: удаляется узел с двумя потомками
				Node* newnode = del;
				newnode = newnode->right;
				while (newnode->left != nullptr)
					newnode = newnode->left;
				T delData = newnode->data;
				this->Delete(delData);
				del->data = delData;
				break;
			}
			}
			size--;
		}
	}
	catch (const std::exception&e)
	{
		cout << "Произошла ошибка: " << e.what() << endl;
	}
}
