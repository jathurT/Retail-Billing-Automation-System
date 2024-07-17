#pragma once
#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Node {
public:
	string elem;
	Node* next;

	Node() { // Default constructor of Node class
		elem = -1;
		next = NULL;
	}

	Node(string e) { //Overloaded constructor of Node class
		elem = e;
		next = NULL;
	}
};

class Singly_Linked_List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	Singly_Linked_List() { // Default constructor of Node class
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Node* getHead() {
		return head;
	}

	Node* getTail() {
		return tail;
	}


	void insertLast(string elem) {
		//Create the node
		Node* temp = new Node(elem);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}


	void print() {
		Node* current = head;

		while (current != NULL) {
			cout << "\t\t\t\t" << current->elem << endl;
			current = current->next;
		}

		cout << endl;
	}

};