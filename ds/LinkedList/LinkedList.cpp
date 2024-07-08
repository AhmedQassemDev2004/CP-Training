#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

template <typename T>
class Node {
public:
  T data;
  Node<T>* next;

  Node(T data) {
    this->data = data;
  }
};

template <typename T>
class LinkedList {
  Node<T>* head;
  int size = 0;

public:
  LinkedList() {
    this->head = NULL;
  }

  void insertLast(T data) {
    Node<T>* node = new Node<T>(data);
    if (this->head == NULL) {
      this->head = node;
    } else {
      Node<T>* current = this->head;
      while (current->next) {
        current = current->next;
      }

      current->next = node;
    }

    this->size++;
  }

  void insertFirst(T data) {
    Node<T>* node = new Node<T>(data);
    if (this->head == NULL) {
      this->head = node;
    } else {
      Node<T>* temp = this->head;
      this->head = node;
      this->head->next = temp;
    }

    this->size++;
  }

  void insertAt(int index, T data) {
    Node<T>* node = new Node<int>(data);

    if (index == 0) {
      insertFirst(data);
    } else if (index >= this->size) {
      insertLast(data);
    } else {
      Node<T>* current = this->head;
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }

      node->next = current->next;
      current->next = node;
    }

    this->size++;
  }

  void deleteFirst() {
    Node<T>* temp = this->head;
    this->head = this->head->next;
    free(temp);
    this->size--;
  }

  void deleteLast() {
    Node<T>* current = this->head;
    for (int i = 1; i < this->size - 1; i++)
      current = current->next;

    Node<T>* last = current->next;
    current->next = NULL;
    free(last);

    this->size--;
  }

  void deleteAt(int index) {
    if (index == 0) {
      this->deleteFirst();
    } else if (index >= size) {
      this->deleteLast();
    } else {
      Node<T>* current = this->head;
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }

      Node<T>* temp = current->next;
      current->next = current->next->next;
      free(temp);
    }
  }

  void display() {
    Node<T>* current = this->head;
    while (current) {
      cout << current->data;
      if (current->next != NULL) {
        cout << " -> ";
      }

      current = current->next;
    }
    cout << '\n';
  }
};

int main() {
  LinkedList<int> list;
  list.insertFirst(5);
  list.insertFirst(4);
  list.insertFirst(3);
  list.insertLast(1);
  list.insertAt(2, 8);
  list.display();
  list.deleteAt(2);
  list.display();
  return 0;
}
