
#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include <iostream>
#include <fstream>
#include <assert.h>
#include "LinkedList.h"
#include "Passenger.h"
using namespace std;


template <class T>
struct node1{
	Passanger data;
	node1* next;
};



template <class T>
class OrderedLinkedList :public LinkedList<T>{
protected:
	node1<T> *head, *last, *p, *q;
	int count;
public:
	OrderedLinkedList();
	bool is_empty();
	int length();
	void insert(T&);             
	template <class U>
	friend ostream& operator<< (ostream& os, OrderedLinkedList<U>& list);
	T search(T&);                     
	void delete_node(T&);             

	T back();
	T front();
	void destroy_list();
	virtual ~OrderedLinkedList();
private:
	void copy_list(LinkedList<T> otherlist);
	
};

//initializing the list: constructor
template <class T>
OrderedLinkedList<T>::OrderedLinkedList(){
	head = NULL;
	last = NULL;
	p = NULL;
	q = NULL;
	count = 0;
	
}
//check if list is empty
template <class T>
bool OrderedLinkedList<T>::is_empty(){
	return head == NULL;
}

//get the number of nodes in the list
template <class T>
int OrderedLinkedList<T>::length(){
	return count;
}

//insert a new item in the list
template <class T>
void OrderedLinkedList<T>::insert(T& item){
	node1<T>* current = new node1<T>;
	current->data = item;
	current->next = NULL;
	if (head == NULL)
	{
		head = last = current;
	}
	else if (item < head->data)
	{
		current->next = head;
		head = current;
	}
	else if (last->data < item)
	{
		last->next = current;
		last = current;
	}
	else{
		p = NULL;
		q = head;
		while (q->data < item){
			p = q;
			q = q->next;
		}
		p->next = current;
		current->next = q;
	}
	count++;
}

template <class T>
ostream& operator<< (ostream& os, OrderedLinkedList<T>& list){
	node1<T>* temp = list.head;
	while (temp != NULL){
		os <<" "<<temp->data.getFirstName()<<" "<< temp->data.getLastName()<<" ["<< temp->data.getAddress()<<"] ["<<temp->data.getPhone()<< "]\n";
		temp = temp->next;
	}
	return os;
}

template <class T>
T OrderedLinkedList<T>::search(T& item){
	node1<T>* temp = head;
	while (head != NULL && temp->data != item){   
		temp = temp->next;
	}

	return temp->data;
}

template <class T>
void OrderedLinkedList<T>::delete_node(T& item){
	node1<T> *p, *q;
	if (head == NULL)
		cout << "List is empty..." << endl;
	else
		if (head->data == item){
			p = head;
			head = head->next;
			delete p;
			count--;
			if (head == NULL)
				last = NULL;
		}
		else{
			p = head;
			q = head->next;
			while (q != NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if (q == NULL)
				cout << "item is not found";
			else{
				p->next = q->next;
				if (q->next == NULL)
					last = p;
				delete q;
				count--;
			}
		}
}

template <class T>
T OrderedLinkedList<T>::back(){
	assert(last != NULL);
	return last->data;
}

template <class T>
T OrderedLinkedList<T>::front(){
	assert(head != NULL);
	return head->data;
}
template <class T>
void OrderedLinkedList<T>::destroy_list(){
	node1<T>* p;
	while (head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

//destructor
template <class T>
OrderedLinkedList<T>::~OrderedLinkedList(){
	cout << "List is destroyed..." << endl;
	destroy_list();
}

#endif /* ORDEREDLINKEDLIST_H_ */


