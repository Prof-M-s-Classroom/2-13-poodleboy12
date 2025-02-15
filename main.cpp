#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
    ~Node() {
        delete value;
    }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    // If head is null there is problems
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }
// If the head is null there will be a problem.
    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }
// If head is null most of these methods will have problems like this one.
    void dellast() {
        Node<T> *temp = head;
        if (head == nullptr) {
            return;
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T> *prev = nullptr;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = nullptr;
            length--;
        }
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        Node<T> *temp = head;
        int currIndex;
        if (index == 0) {
            head = temp->next;
            delete temp;
            length--;
        }
        else {
            currIndex = 0;
            while(temp != nullptr && currIndex != index - 1) {
                temp = temp->next;
                ++currIndex;
            }
            if (temp != nullptr) {
                Node<T> *temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
                length--;
            }
        }
    }
 // You don't know when head is null. If head is null there is an issue.
    Node<T>* get(int index) {
        if(index < 0 || index>=length)
            return nullptr;
        Node<T>* temp = head;
        for(int i = 0; i < index; i++)
            temp=temp->next;

        return temp;
    }

    // Your code will fail if head is null.
    void insert(int index, T* value) {
        if (index < 0 || index > length) {
            cout << "Index is invalid" << endl;
            return; // You need it here for an error case.
        }
        if (index==0){
            addhead(value);
        }
        if(index==length) {
            add(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
        return; // Return doesn't matter because it will return even if it doesn't exist.
    }


    void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* prev;
        Node<T>* curr;
        Node<T>* next;
        prev = nullptr;
        curr = head;
        while (curr!=nullptr) {
            next = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->dellast();
    ll->print();
}