#include <iostream>

class Node 
{
public:
    Node(int el = 0, Node *ptr = nullptr):
        info(el), next(ptr) { }
    int info;
    Node *next;        
};

class Nodelist
{
public:
    Nodelist(): head(nullptr), slist_size(0){}
    ~Nodelist();
    bool checkindex(int index);
    void AddToTail(int data = 0);
    void AddTohead(int data = 0);
    int Search(int data = 0);
    void deleteNode(int index);
    void printList();
    bool empty() const {return slist_size ? false : true;}
    int size() const {return slist_size;}

private:
    Node *head;
    int slist_size;
};

bool Nodelist::checkindex(int index)
{
    if(index < 0 || index > slist_size -1)
    {
        std::cout << "Error index value" << std::endl;
        return false;
    }    
    else
    {
        return true;
    }
    
}

Nodelist::~Nodelist()
{
    while(head!=nullptr)
    {
        Node *ptr = head;
        head = ptr ->next;
        delete ptr;
    }
}
void Nodelist::AddTohead(int data)
{
    if(head == nullptr)
    {
        head = new Node(data);
        head->next = nullptr;
        ++slist_size;
    }
    else
    {
        Node *ptr = new Node(data);
        ptr->next = head;
        head = ptr;
        ++slist_size;
    }
}

void Nodelist::AddToTail(int data)
{
    if(head == nullptr)
    {
        head = new Node(data);
        head->next = nullptr;
        ++slist_size;
    }
    else
    {
        Node *ptr = new Node(data);
        Node *thenode = head;
        while(thenode->next != nullptr)
        {
            thenode = thenode->next;
        } 
        thenode->next = ptr;
        ++slist_size;
    }    
}

int Nodelist::Search(int data)
{
    Node *ptr = head;
    for(int i = 0; i <= slist_size; ++i)
    {
        if(ptr->info != data)
            ptr = ptr->next;
        else
            return i;
    }
    return -1;
}

void Nodelist::deleteNode(int index)
{
    Node *ptr = head;
    Node *NodeToDelete;
    if(!checkindex(index))
        return;
    else
    {
        if(index == 0)
        {
            NodeToDelete = ptr;            
            head = head->next; 
        }
        else
        {
            for(int i = 0; i < (index - 1); ++i)
            {
                ptr = ptr->next;
            }    
            NodeToDelete = ptr->next;
            ptr -> next = NodeToDelete->next; 
        }
    }
    --slist_size;
    delete NodeToDelete;
}

void Nodelist::printList()
{
    Node *ptr = head;
    std::cout << "slist : " <<std::endl;
    for(int i = 0; i < slist_size - 1; ++i)
    {
        std::cout << ptr->info << "->" ;
        ptr = ptr->next;
    }    
    std::cout << ptr->info << std::endl;
}
int main()
{
    Nodelist mylist;
    mylist.AddTohead(1);
    mylist.AddTohead(3);
    mylist.AddTohead(5);
    mylist.AddTohead(7);
    mylist.AddTohead(9);
    mylist.AddToTail(2);
    mylist.AddToTail(4);
    mylist.AddToTail(6);
    mylist.printList();
    std::cout << mylist.size() << std::endl;
    mylist.deleteNode(0);
    mylist.printList();
    mylist.deleteNode(9);
    mylist.printList();
    mylist.deleteNode(6);
    mylist.printList();
    mylist.deleteNode(4);
    mylist.printList();
    
    std::cout << "3 is at : " << mylist.Search(3) << std::endl;

    mylist.~Nodelist();
    return 0;
}