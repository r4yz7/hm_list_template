#ifndef ASDLIST_H
#define ASDLIST_H

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class ASDList {
private:
    Node<T>* head;
    int size;

public:
    ASDList() : head(nullptr), size(0) {}
    ~ASDList() {
        Node<T>* current = head;
        Node<T>* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    Node<T>* getHead() const {
        return head;
    }

    void addElement(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (newNode == nullptr) {
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    void countEvenOddNegative(int& evenCount, int& oddCount, int& negativeCount) {
        evenCount = 0;
        oddCount = 0;
        negativeCount = 0;

        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }

            if (current->data < 0) {
                negativeCount++;
            }

            current = current->next;
        }
    }
};

#endif
