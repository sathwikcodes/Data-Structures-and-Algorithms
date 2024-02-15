#include<iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;

    public: 
        Node(int value){
            this->value = value;
            next = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        void printList()
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        ~LinkedList() {
            Node *temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void getHead(){
            cout << "Head:" << head->value << endl;
        }
        void getTail()
        {
            cout << "Tail:" << tail->value << endl;
        }
        void getLength()
        {
            cout << "Length:" << this->length << endl;
        }
        void append(int value){
            Node *newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;

            }else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void DeleteLast(){
            if(length == 0 ) return;
            Node *temp = head;
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
                }else {
                    Node *pre = head;
                    while (temp->next)
                    {
                        pre = temp;
                        temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
                }
                delete temp;
                length--;
        }

        void Prepend(int value){
            Node *newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
                
            }
            length++;
        }

        void DeleteFirst(){
            if(length == 1){
                head = nullptr;
                tail = nullptr;
            }else{
                Node *oldHead = head;
                head = head->next;
                delete oldHead;
            }
            length--;
        }

        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
                Node* temp = head;
                for (int i = 0; i < index; i++){
                    temp = temp->next;
                }
                
            return temp;
        }

        bool set(int index, int value){
            Node *temp = get(index);
            if(temp){
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index,int value){
            Node *newNode = new Node(value);
            if(index < 0 || index > length){
                return false;
            }else if(index == 0){
                Prepend(value);
                return true;
            }else if(index = length){
                append(value);
                return true;
            }else{
                Node *temp = get(index);
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return true;
            }
        }

        bool insertWgetnset(int index, int value){
            Node *newNode = new Node(value);
            Node *temp = head;
            for (int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }

        void DeleteNode(int index){
            if(index < 0 || index > length)
                return;
            else if(index == 0)
                DeleteFirst();
            else if(index == length - 1) 
                DeleteLast();
            else{
                Node *prev = get(index - 1);
                Node *temp = prev->next;
                prev->next = temp->next;
                delete temp;
                length--;
            }
        }


        void Reverse(){
            Node *temp = head;
            head = tail;
            tail = head;
            Node *before = nullptr;
            Node *after = temp->next;
            for (int i = 0; i < length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }


 };

int main(){
    LinkedList *List = new LinkedList(4);
    List->append(10);
    List->append(12);
    List->Prepend(20);
    // List->set(2, 100);
    List->DeleteNode(2);
    // // List->insert(0, 343434);
    // // List->insertWgetnset(2, 59457985);
    // // List->DeleteFirst();
    
    // // List->DeleteLast();
    List->getHead();
    List->getTail();
    List->getLength();
    List->Reverse();
    // // cout << "Value here:"<<List->get(2)->value << endl;
    List->printList();
    
}