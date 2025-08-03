#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int val): data(val), next(nullptr) {}
};

class LinkedList {
private:
  Node* head;

public:
  LinkedList() : head(nullptr) {}

  void append(int val) {
    Node *newNode = new Node(val);

    if(!head) {
      head = newNode;
      return;
    }

    Node *temp = head;
    while(temp->next) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  void prepend(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  // Removes first occurence of value
  void remove(int value) {
    if(!head) return;

    if(head->data == value) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *temp = head;
    Node *prev = nullptr;
    while(temp && temp->data != value) {
      prev = temp;
      temp = temp->next;
    }

    if(temp) {
      prev->next = temp->next;
      temp->next = nullptr;
      delete temp;
    }
  }

  ~LinkedList() {
    Node *temp = head;

    while(temp) {
      Node *next = temp->next;
      delete temp;
      temp = next;
    }
  }

  void print() const {
    Node *temp = head;

    while(temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
};

// --- Simple Tests ---
int main() {
    LinkedList list;

    cout << "Appending 10, 20, 30:\n";
    list.append(10);
    list.append(20);
    list.append(30);
    list.print(); // Expected: 10 -> 20 -> 30 -> NULL

    cout << "\nPrepending 5:\n";
    list.prepend(5);
    list.print(); // Expected: 5 -> 10 -> 20 -> 30 -> NULL

    cout << "\nDeleting 20:\n";
    list.remove(20);
    list.print(); // Expected: 5 -> 10 -> 30 -> NULL

    cout << "\nDeleting head (5):\n";
    list.remove(5);
    list.print(); // Expected: 10 -> 30 -> NULL

    cout << "\nDeleting non-existing value (100):\n";
    list.remove(100);
    list.print(); // Expected: 10 -> 30 -> NULL

    return 0;
}
