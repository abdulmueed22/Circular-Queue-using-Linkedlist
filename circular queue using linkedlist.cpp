#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (rear == NULL) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (rear == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        } else if (rear->next == rear) {
            delete rear;
            rear = NULL;
        } else {
            Node* temp = rear->next;
            rear->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (rear == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = rear->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
   
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<endl;
   
    cout<<"Displaying my Queue list\n";
    q.display();
   
    q.dequeue();
   
    q.enqueue(6);
   
     cout<<"Displaying my Queue list\n";
    q.display();

    return 0;
}
