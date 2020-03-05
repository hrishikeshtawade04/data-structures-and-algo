#include <iostream>

using namespace std;


class Node {
    public:
        int data;
        Node(int data) : data(data){}
        Node *next = nullptr;
};

class List {
    public:
        Node *head = nullptr;
        void insertBack(Node *newNode) {
            if(head == nullptr)
                head = newNode;
            else
            {
                Node *temp = head;
                while(temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;    
            }
        }
        void insert(Node *newNode, int index) {
            Node *temp = head;
            int count = 0;
            if(index == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }
            while(count < index-1 && temp != nullptr) {
                temp = temp->next;
            }
            if(temp == nullptr) {
                cerr << "Index not found";
                return;
            }
            Node *temp1 = temp->next;
            temp->next = newNode;
            temp->next->next = temp1;
        }
        void print() {
            Node *temp = head;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    List newlist;
    Node* node1 = new Node(1);
    newlist.insertBack(node1);
    Node* node2 = new Node(2);
    newlist.insertBack(node2);
    Node* node3 = new Node(3);
    newlist.insert(node3,0);
    newlist.print();
    return 0;
}