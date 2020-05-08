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
			if (size == 0) {//���� ������ �����, �� ������� �� ����� ���� ������.
				return nullptr;
			}
			else
				while (temp != nullptr&&temp->data != Data) {
					if (Data < temp->data) {//������� ������
						temp = temp->left;//������� � ������ �������.
					}
					else {//������� �������
						temp = temp->right;//������� � ������ �������.
					}
				}
			return temp;//���� ������� ������, �� ����� ���������� ������ �� ����, ����� - �������
		}
		catch (const std::exception&e)
		{
			cout << "��������� ������: " << e.what() << endl;
		}
	}
	void detour(Node* node) {//����������� ��������
		Node* n = node;
		cout << n->data << endl;//����� �������
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
			cout << n->data << endl;//����� �������
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
	bool is_Exist(T Data) {//��������, ���������� �� �������.
		if (Find(Data) == nullptr)
			return false;
		else
			return true;
	}
	BinaryTree() :root(nullptr), size(0) {}
	~BinaryTree() {}
	void Add(T);//�������� �������
	void Delete(T);//������� �������
	void Detour();//����� ������ ������
	void Lists();//������ �������
};
//���������� �������
template<typename T>
inline void BinaryTree<T>::Lists()
{
	cout << "������ �������:\n";
	if (size > 0)
		lists(this->root);
	else
		cout << "�������� ������ �����.";
}
template<typename T>
inline void BinaryTree<T>::Detour()
{
	cout << "����� ������ ������:\n";
	if (size > 0)
		detour(this->root);
	else
		cout << "�������� ������ �����.";
}
template<typename T>
inline void BinaryTree<T>::Add(T Data)
{
	try {
		Node* temp = this->root;
		bool done = false;
		if (size == 0) {//���� ������ �����, �� �������� ������
			Node* list = new Node(Data);
			this->root = list;//������ root ��������� �� ������.
		}
		else
			while (!done) {
				if (Data < temp->data) {//������� ������
					if (temp->left == nullptr) {//���� � ���� ��� ������ �������, ��
						Node* list = new Node(Data);//������� ��������� �� ����� ����
						temp->left = list;//�������� ������ ������ �� ���� ����
						done = true;//����� �� �����
					}
					else {
						temp = temp->left;//����� ������� � ������ �������.
					}
				}
				else {//������� �������
					if (temp->right == nullptr) {//���� � ���� ��� ������� �������, ��
						Node* list = new Node(Data);//������� ����� ����
						temp->right = list;//�������� ������ ������ �� ���� ����
						done = true;//����� �� �����
					}
					else {
						temp = temp->right;//����� ������� � ������� �������.
					}
				}
			}
		size++;
	}
	catch (const std::exception&e)
	{
		cout << "��������� ������: " << e.what() << endl;
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
				if (Data < del->data) {//������� ������
					delP = del;
					del = del->left;//������� � ������ �������.
					delleft = true;
				}
				else {//������� �������
					delP = del;
					del = del->right;//������� � ������� �������.
					delleft = false;
				}
			}
			if (del->left != nullptr)ivent++;
			if (del->right != nullptr)ivent++;
			switch (ivent)
			{
			case 0: {//�������� 0: ��������� ����(���� ��� ��������)
				delete del;
				if (delleft)
					delP->left = nullptr;
				else
					delP->right = nullptr;
				break;
			}
			case 1: {//�������� 1: ��������� ���� � ����� ��������
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
			case 2: {//�������� 2: ��������� ���� � ����� ���������
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
		cout << "��������� ������: " << e.what() << endl;
	}
}
