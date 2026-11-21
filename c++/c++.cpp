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
	// IS EMPTY 
	bool IsEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	// COUNT 
	int Count(int value) {
		node* firstNode = head;
		int count = 0;
		while (firstNode != NULL) {
			if (firstNode->value == value) {
				count++;
			}
			firstNode = firstNode->next;
		}
		return count;
	}
	// MAX 
	int Max() {
		node* startNode = head;
		node* max = head;
		while (startNode != NULL) {
			if (startNode->value > max->value) {
				max = startNode;
			}
			startNode = startNode->next;
		}
		return max->value;

	};
	// MIN 
	int Min() {
		node* startNode = head;
		node* min = head;
		while (startNode != NULL) {
			if (startNode->value < min->value) {
				min = startNode;
			}
			startNode = startNode->next;
		}
		return min->value;

	};
	// SUM 
	int Sum() {
		node* startNode = head;
		int sum = 0;
		while (startNode != NULL) {
			sum += startNode->value;
			startNode = startNode->next;
		}
		return sum;
	};
	// Print Reverse
	void PrintReverse() {
		if (head == NULL) {
			cout << "⚠️ LIST IS EMPTY";
		}
		node* startNode = tail;
		cout << "\nLIST IS : \n";
		while (startNode !=NULL) {
			cout <<  startNode->value << "\t";
			startNode = startNode->back;
		}
	}
	// Retrieve by index
	int Retrieve(int index) {
		node* startNode = head;
		int count = 0;
		while (startNode != NULL) {
			if (count == index) {
			
				return startNode->value;
			}
			startNode = startNode->next;
			count++;
		}
		return -1;
	}
	// Retrieve by value 
	int RetrieveByValue(int value) {
		node* startNode = head;
		int count = 0;
		while (startNode != NULL) {
			if (startNode->value == value) {

				return count;
			}
			startNode = startNode->next;
			count++;
		}
		return -1;
	};
	// DELETE AT FIRST 
	void DeleteAtStart() {
		node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->back = NULL;
		}
		else {
			tail = NULL;
		}
		delete temp;
		counter--;
	};
	// DELETE AT END 
	void DeleteAtEnd() {
		node* temp = tail;
		tail = tail->back;
		if (tail != NULL) {
			tail->next = NULL;
		}
		else {
			head = NULL;
		}
		delete temp;
		counter--;
	};
	// DELETE BY VALUE 
	void DeleteValue(int value) {
		node* temp = head;
		while (temp != NULL && temp->value != value) {
			temp = temp->next;
		}
		if (temp->back != NULL) {
			temp->back->next = temp->back;
		}
		if (temp->next != NULL) {
			temp->next->back = temp->next;
		}
		delete temp;
		counter--;
	};
	void MoveEvenToEnd() {
		if (head == NULL || head->next == NULL) {
			return; // empty or single node: nothing to do
		}
		node* oddHead = NULL;
		node* oddTail = NULL;
		node* evenHead = NULL;
		node* evenTail = NULL;
		node* current = head;
		while (current != NULL) {
			node* nextNode = current->next;
			if (current->value % 2 == 0) {
				if (oddHead == NULL) {
					oddHead = oddTail = current;
				}
				else {
					oddTail->next = current;
					oddTail = current;
				}
			}
			else {
				if (evenHead == NULL) {
					evenHead = evenTail = current;
				}
				else {
					evenTail->next = current;
					evenTail = current;
				}
			}
			current = nextNode;
		}
		if (oddHead == NULL) {
			head = evenHead;
			tail = evenTail;
		}
		else {
			oddTail->next = evenHead;
			head = oddHead;
			tail = (evenTail != NULL) ? evenTail : oddTail;
		}

	}



};
int main() {
	List l;
	l.InsertAtFirst(10);
	l.Insert(20, l.First());
	l.Insert(30, NULL);
	l.Insert(40, NULL);
	l.Insert(50, NULL);
	l.Insert(60, l.First());
	l.Insert(70, NULL);
	cout << "ELMENT COUNT IS = " << l.Count(100);
	cout << "\nMAX IS = " << l.Max();
	cout << "\nMIN IS = " << l.Min();
	cout << "\nSUM IS = " << l.Sum();
	cout << "\nELEMENT IS = " << l.Retrieve(1);
	cout << "\nELEMENT BY VALUE IS = " << l.RetrieveByValue(20);
    l.PrintReverse();
	return 0;
}