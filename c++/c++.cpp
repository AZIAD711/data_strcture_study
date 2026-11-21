#include <iostream>
using namespace std;
struct node
{
	int value;
	node* next;
	node* back;
};
class List {
	// DATA
private:
	int counter;
	node* head;
	node* tail;
public:
	// CONSUCTOR 
	List() {
		MakeNull();
	};
	// MAKE NULL 
	void MakeNull() {
		head = NULL;
		tail = NULL;
		counter = 0;
	};
	node* END() {
		return tail;
	};
	node* First() {
		return head;
	};
	// INSERT AT FIRST 
	void InsertAtFirst(int value) {
		node* newNode = new node;
		newNode->value = value;
		newNode->next = head;
		newNode->back = NULL;

		if (head != NULL)
			head->back = newNode;
		else
			tail = newNode;

		head = newNode;
		counter++;
	}
	// INSERT AT END 
	void InsertAtEnd(int value) {
		node* newNode = new node;
		newNode->value = value;
		newNode->next = NULL;
		newNode->back = tail;

		if (tail != NULL)
			tail->next = newNode;
		else
			head = newNode;

		tail = newNode;
		counter++;
	}
	// INSERT 
	void Insert(int value, node* p) {
		if (p == NULL) {
			InsertAtEnd(value);
		}
		else if (p == head) {
			InsertAtFirst(value);
		}
		else {
			node* newNode = new node;
			newNode->value = value;
			newNode->back = p;
			newNode->next = p;
			p->back->next = newNode;
			p->back = newNode;
			counter++;
		}
	}
	// NEXT 
	node* Next(node* p) {
		if (p == NULL) return NULL;
		return p->next;
	};
	// PREVIOUS 
	node* Previous(node* p) {
		if (p == NULL) return NULL;
		return p->back;
	};
	// LOCATE 
	node* Locate(int value) {
		node* p = head;
		while (p != NULL) {
			if (p->value == value) return p;
			p = p->next;
		}
		return p;
	};
	// LAST 
	int Last() {
		return tail->value;
	}

};
int main() {
	List l;
	l.InsertAtFirst(1);
	l.Insert(-90, l.First());
	l.Insert(100, NULL);
	l.Insert(400, NULL);
	l.Insert(-200, l.First());
	l.Insert(534, NULL);
	return 0;
}