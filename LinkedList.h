#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <fstream>
#include "Passenger.h"
using namespace std;

template <class T>
struct node{
	Passanger data;
	node* next;
};



template <class T>
class LinkedList{
protected:
	node<T> *head, *last;
	int count;
public:
	LinkedList();
	bool is_empty();
	int length();
	void insert_first(T&);
	void insert_last(T&);
	template <class U>
	friend ostream& operator<< (ostream& os, LinkedList<U>& list);
	T search(T&);
	void delete_node(T&);

	T back();
	T front();
	void destroy_list();
	virtual ~LinkedList();
private:
	void copy_list(LinkedList<T> otherlist);

};

//initializing the list: constructor
template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	last = NULL;
	count = 0;

}
//check if list is empty
template <class T>
bool LinkedList<T>::is_empty(){
	return head == NULL;
}

//get the number of nodes in the list
template <class T>
int LinkedList<T>::length(){
	return count;
}

//insert a new lelement to the front
template <class T>
void LinkedList<T>::insert_first(T& item){
	node<T>* current = new node<T>;
	current->data = item;
	current->next = NULL;
	if (head != NULL){
		current->next = head;
		head = current;
	}
	else{
		head = last = current;
	}
	count++;
}

//insert a new item at the end of the list
template <class T>
void LinkedList<T>::insert_last(T& item){
	node<T>* current = new node<T>;
	current->data = item;
	current->next = NULL;
	if (head != NULL){
		last->next = current;
		last = current;

	}
	else{
		head = last = current;
	}
	count++;
}

template <class T>
ostream& operator<< (ostream& os, LinkedList<T>& list){  
	node<T>* temp = list.head;
	while (temp != NULL){
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}

template <class T>
T LinkedList<T>::search(T& item){             
	node<T>* temp = head;
	while (head != NULL && temp->data != item){
		temp = temp->next;
	}

	return temp->data;
}

template <class T>
void LinkedList<T>::delete_node(T& item){
	node<T> *p, *q;
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
T LinkedList<T>::back(){   
	assert(last != NULL);
	return last->data;
}

template <class T>
T LinkedList<T>::front(){   
	assert(head != NULL);
	return head->data;
}
template <class T>
void LinkedList<T>::destroy_list(){
	node<T>* p;
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
LinkedList<T>::~LinkedList(){
	cout << "List is destroyed..." << endl;
	destroy_list();
}

#endif /* LINKEDLIST_H_ */
