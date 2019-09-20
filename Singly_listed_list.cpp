
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data); //добавление элемента в конец списка
	void pop_front();  //удаление первого элемента списка
	void clear();  //удаление списка
	void push_front(T data); // добавление элемента в начало списка
	void insert(T data, int index);   //добавлени узла внутрь листа
	void removeAt(int index);   //удаление узла (элемета) по индексу
	void pop_back(); //удаление последнего элемента списка
	int GetSize() { return Size; }
	T& operator[](int const index) //перегрузка [] для доступа к данным по индексу элемента
	{
		int counter = 0;
		Node<T> *current = this->head;
		while (current->pNext != nullptr){
			if (counter == index){return current->data;}
			current = current->pNext;
			counter++;
		}
	}
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node *pNext;
		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size; //колличеств элементов в списке
	Node<T> *head; //узел списка с адресом следующего элемента и данными
};

template<typename T>
List<T>::List(){
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List(){
	clear();
}

template<typename T>
void List<T>::push_back(T data){
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::pop_front(){
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear(){
	while (Size)	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data){
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index){
	if (index == 0)	{
		push_front(data);
	}
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i = index - 1; i++)	{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index){
	if (index == 0)	{pop_front();}
	else {
		Node<T> *previous = head;
		for (int i = 0; i < index - 1; i++)		{
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back(){
	removeAt(Size - 1);
}

int main() {
	setlocale(LC_ALL, "ru");
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);
	cout << lst.GetSize() << endl;

	for (int i = 0; i < lst.GetSize(); i++)	{
		cout << lst[i] << ",";
	}
	cout << endl;
	lst.insert(6, 1);
	cout << lst.GetSize() << endl;
	for (int i = 0; i < lst.GetSize(); i++)	{
		cout << lst[i] << ",";
	}
	cout << endl;
	lst.removeAt(1);
	for (int i = 0; i < lst.GetSize(); i++)	{
		cout << lst[i] << ",";
	}
	cout << endl;
	return 0;
}



