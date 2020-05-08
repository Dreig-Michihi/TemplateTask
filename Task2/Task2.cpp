// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	BinaryTree<int> tree;
	tree.Add(3);
	tree.Add(1);
	tree.Add(9);
	tree.Add(1);
	tree.Add(5);
	tree.Add(10);
	tree.Add(4);
	tree.Add(7);
	tree.Add(6);
	tree.Add(8);
	tree.Detour();
	tree.Lists();
	cout << "Delete 4,5,3\n";
	tree.Delete(4);
	tree.Delete(5);
	tree.Delete(3);
	tree.Detour();
	tree.Lists();
	return 0;
}