/*
Ramamurthy Sundar
class.h

This file includes the declaration LinkedList class.  It also includes both the
declaration and implementation of the Iterator friend class.

The Iterator class is a custom iterator for the linked list.  It will allow us to
keep the node struct data private and secure, while still being able to access LinkedList
elements.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //for int rand()

//definition of the student linked list
template <typename T>
class LinkedList {
private:
	//node struct for singlely linked list
	struct Node
	{
		Node *next;
		T data;
	};
	Node *head;
	Node *tail;
	int count;

//iterator class
public:
	class Iterator {
	private:
		//current Iterator position is a List node
		Node *node_ptr;
		friend class LinkedList;

	public:
		//default ctor
		Iterator() {};
		//copy constructor
		Iterator(Node *ptr) {
			node_ptr = ptr;
		}
		//dereferece pointer
		T& operator*() {
			return node_ptr->data;
		}
		//traverse to next in list
		Iterator& operator++() {
			node_ptr = node_ptr->next;
			return *this;
		}
		//return next node in iterator
		Iterator next_node() {
			return Iterator(node_ptr->next);
		}
		//2 boolean operation overloads
		bool operator==(const Iterator &rhs) const {
			return node_ptr == rhs.node_ptr;
		}
		bool operator!=(const Iterator &rhs) const {
			return node_ptr != rhs.node_ptr;
		}
	};//LinkedList::Iterator

//LinkedList member functions
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~LinkedList();
	bool isEmpty() const;
	int length() const;
	T front() const;
	T back() const;
	Iterator begin();
	Iterator end();
	void print();
	void print_to_txt(std::ofstream &outfile);
	void insert_front(const T& item);
	void delete_node(const T& item);
	void bubble_sort();
	void remove_duplicates();
	void splice(Iterator& head2, Iterator& head3);
	int sum() const;
	double average() const;
};
