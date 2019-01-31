/*
Ramamurthy Sundar
class.cpp

Implementation of class.h. All functions are commented bellow.
*/

#include "class.h"

//destructor
template<typename T>
LinkedList<T>::~LinkedList() {
	Node *temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	count = 0;
}

//returns true is the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const {
	if (head == nullptr && tail == nullptr) return true;
	else return false;
}

//return length of list
template <typename T>
int LinkedList<T>::length() const {
	return count;
}

//return data in head node
template <typename T>
T LinkedList<T>::front() const {
	return head->data;
}

//return data in tail node
template <typename T>
T LinkedList<T>::back() const {
	return tail->data;
}

//returns an iterator to the head of the list
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(head);
}

//returns an iterator to the tail of the list
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
	return Iterator(nullptr);
}

//print list to console
template<typename T>
void LinkedList<T>::print() {
	Node *temp = head;
	while (temp != nullptr) {
		if (temp == tail) {
			std::cout << temp->data << std::endl;
		}
		else {
			std::cout << temp->data << ", ";
		}
		temp = temp->next; 
	}
}

//print list to a line in a text file
template<typename T>
void LinkedList<T>::print_to_txt(std::ofstream &outfile) {
	Node *temp = head;
	while (temp != nullptr) {
		if (temp == tail) {
			outfile << temp->data << "\n";
		}
		else {
			outfile << temp->data << ", ";
		}
		temp = temp->next;
	}
}

//insert in the front of the list
template<typename T>
void LinkedList<T>::insert_front(const T & item){
	//insertion for case for empty list
	if (isEmpty()) {
		Node *temp = new Node;
		temp->data = item;
		temp->next = head;
		head = temp;
		tail = temp;
		count++;
	}
	//insertion for case of non-empty list
	else {
		Node *temp = new Node;
		temp->data = item;
		temp->next = head;
		head = temp;
		count++;
	}
}

//REQUIRES: linked list is not empty
//delete any node in the list given the data
template<typename T>
void LinkedList<T>::delete_node(const T & item) {
	//deletion for case of list with size 1
	if (count == 1) {
		Node *temp = new Node;
		temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
	}
	else {
		Node *i;
		for (i = head; i != nullptr; i = i->next) {
			if (i->data == item) {
				Node *temp = new Node;
				temp = i->next;
				i->next = temp->next;
				delete temp;
				count--;
			}
		}
	}
}

//sort a linked list by swapping the values in the list
//is a bubble_sort algorithm
template<typename T>
void LinkedList<T>::bubble_sort() {
	Node *i,*j; 
	auto tempvalue = head->data;
	for (i = head; i != nullptr; i = i->next) {
		for (j = i->next; j != nullptr; j = j->next) {
			if (i->data > j->data) {
				tempvalue = i -> data;
				i->data = j->data;
				j->data = tempvalue;
			}
		}
	}
}

//Requires: A sorted linked list
//Removes duplicate elements in a list
template<typename T>
void LinkedList<T>::remove_duplicates() {
	Node *i = head; Node *j;
	if (!isEmpty()) {
		while (i->next != nullptr) {
			//case for deletion
			if (i->data == i->next->data) {
				j = i->next->next;
				//delete node takes in 
				delete_node(i->next->data);
				i->next = j;
			}
			//only advance is there is no deletion, else you get memory access error
			else {
				i = i->next;
			}
		}
	}
}

//Requires: 2 iterators to a sorted linked list with no duplicates
//takes 2 linked list iterators as input and combines them into a new linked list
template<typename T>
void LinkedList<T>::splice(typename LinkedList<T>::Iterator &head1, typename LinkedList<T>::Iterator &head2) {
	
	typename LinkedList<T>::Iterator head3 = begin(), tempIterator;

	//Case 1: the lists are empty
	if (head1 == nullptr) return;
	if (head2 == nullptr) return;
	
	//Case 2: the lists have elements
	//assign initial value of heads to head3 
	if (*head1 <= *head2) {
		head3 = head1;
		head1 = head3.next_node();
	}
	else {
		head3 = head2;
		head2 = head3.next_node();
	}
	insert_front(*head3);
	//assign the rest of the values to the list
	while (head1!=nullptr && head2!=nullptr) {
		if (*head1 <= *head2) {
			tempIterator = head3.next_node();
			tempIterator = head1;
			head3 = head1;
			head1 = head3.next_node();
		}
		else {
			tempIterator = head3.next_node();
			tempIterator = head2;
			head3 = head2;
			head2 = head3.next_node();
		}
		insert_front(*head3);
	}
	//assign the last node to the new list
	if (head1 == nullptr) {
		tempIterator = head3.next_node();
		tempIterator = head2;
	}
	if (head2 == nullptr) {
		tempIterator = head3.next_node();
		tempIterator = head1;
	}
	insert_front(*tempIterator);
}

//returns the integer sum of the elements in the list
int LinkedList<int>::sum() const
{
	int total = 0;
	Node *temp = head;
	while (temp != nullptr) {
		total += temp->data;
		temp = temp->next;
	}
	return total;
}

//returns the floating point average of the elements in the list
double LinkedList<int>::average() const
{
	int total = sum();
	double average = (double)total / (double)count;
	return average;
}

//potential types that will be used in main
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;
template class LinkedList<char*>;

