#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findUnion(Node* h1, Node* h2) {
    unordered_set<int> h;
    Node* result = nullptr;
    Node* temp = h1;
    while (temp != nullptr) {
        h.insert(temp->data);
        temp = temp->next;
    }
    temp = h2;
    while (temp != nullptr) {
        h.insert(temp->data);
        temp = temp->next;
    }
    for (auto i : h) {
        insert(result, i);
    }
    return result;
}

Node* findIntersection(Node* h1, Node* h2) {
    unordered_set<int> h;
    Node* result = nullptr;
    Node* temp = h1;
    while (temp != nullptr) {
        h.insert(temp->data);
        temp = temp->next;
    }
    temp = h2;
    while (temp != nullptr) {
        if (h.find(temp->data) != h.end()) {
            insert(result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;
    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 3);
    insert(l1, 4);
    insert(l2, 3);
    insert(l2, 1);
    insert(l2, 5);
    insert(l2, 7);

    cout << "List 1: ";
    print(l1);
    cout << "List 2: ";
    print(l2);

    Node* unionList = findUnion(l1, l2);
    cout << "Union: ";
    print(unionList);

    Node* intersectionList = findIntersection(l1, l2);
    cout << "Intersection: ";
    print(intersectionList);

    return 0;
}
