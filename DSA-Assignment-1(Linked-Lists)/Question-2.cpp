//#include <iostream>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//    Node* random;
//
//    Node(int val)
//    {
//        data = val;
//        next = NULL;
//        random = NULL;
//    }
//};
//
//class SinglyLinkedList
//{
//private:
//    Node* head;
//
//public:
//
//    SinglyLinkedList()
//    {
//        head = NULL;
//    }
//
//    ~SinglyLinkedList()
//    {
//        Node* current = head;
//
//        while (current != NULL)
//        {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//
//        head = NULL;
//    }
//
//    void insert(int value)
//    {
//        Node* newNode = new Node(value);
//
//        if (head == NULL)
//        {
//            head = newNode;
//            return;
//        }
//
//        Node* current = head;
//
//        while (current->next != NULL)
//        {
//            current = current->next;
//        }
//
//        current->next = newNode;
//    }
//
//    Node* getHead()
//    {
//        return head;
//    }
//
//    Node* clone()
//    {
//        if (head == NULL)
//        {
//            return NULL;
//        }
//
//        Node* current = head;
//
//        while (current != NULL)
//        {
//            Node* copy = new Node(current->data);
//
//            copy->next = current->next;
//            current->next = copy;
//
//            current = copy->next;
//        }
//
//        current = head;
//
//        while (current != NULL)
//        {
//            if (current->random != NULL)
//            {
//                current->next->random =current->random->next;
//            }
//
//            current = current->next->next;
//        }
//
//        Node* cloneHead = head->next;
//
//        current = head;
//
//        while (current != NULL)
//        {
//            Node* copy = current->next;
//
//            current->next = copy->next;
//
//            if (copy->next != NULL)
//            {
//                copy->next = copy->next->next;
//            }
//
//            current = current->next;
//        }
//
//        return cloneHead;
//    }
//};
