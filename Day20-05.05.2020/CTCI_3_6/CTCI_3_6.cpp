//		CTCI Chapter 3 Problem 6
//		    Stacks and Queues
//		     Animal Shelter
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Linked_List
{
    int size;
private:
    Node *head;
public:
    Linked_List()
    {
        this->head = NULL;
        this->size = 0;
    }
    bool empty()
    {
        if(!size)
        {
            return true;
        }
        return false;
    }
    int value_at(int index)
    {
        if(size<=index || head==NULL)
        {
            return NULL;
        }
        Node *current = head;
        for(int count=0;count<index;count++)
        {
            current = current->next;
        }
        return current->data;
    }
    void push_front(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = head;
        head = temp;
        size++;                             // Size increases when element is inserted
    }
    int pop_front()
    {
        if(head==NULL) exit(1);                    // If there is no element, head is NULL, so do nothing
        int res = head->data;
        head = head->next;
        size--;
        return res;
    }
    void push_back(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = NULL;                 //Since this is the last element, its next must be NULL
        if(head==NULL){
            head = temp;
            size++;
            return;
        }
        Node *current = head;
        for(int i=0;i<size-1;i++)
        {
            current = current->next;
        }
        current->next = temp;             //Previously last element now points at the new last element
        size++;
    }
    void remove_value(int value)
    {
        if(head==NULL)
        {
            return;
        }
        if(head->data==value)
        {
            head = head->next;
            size--;
            return;
        }
        Node *current = head;
        Node *after = head->next;                      // We check if the after's data is equal to value or not
        while(after->data!=value)
        {
            current = current->next;
            after = after->next;
            if(after==NULL)
            {
                return;
            }
        }
        current->next = after->next;
        size--;
    }
    void print()
    {
        Node *current = head;
        while(current!=NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};
class Animal_Shelter
{
    // Odds are cat , Evens are Dogs
public:
    Linked_List cat; // Instantiating an object of class Linked_List
    Linked_List dog;
    Linked_List any;
    Animal_Shelter()
    {
        this->cat = cat;
        this->dog = dog;
        this->any = any;
    }
    void enqueue(int animal)
    {
        if(animal%2) cat.push_back(animal);
        else dog.push_back(animal);
        any.push_back(animal);
    }
    int dequeueAny()
    {
        if(!any.empty())
        {
            int removed = any.pop_front();
            if(removed%2) cat.pop_front();
            else dog.pop_front();
            return removed;
        }
        else exit(1);
    }
    int dequeueCat()
    {
        if(!any.empty())
        {
            int removed = cat.pop_front();
            any.remove_value(removed);
            return removed;
        }
        else exit(1);
    }
    int dequeueDog()
    {
        if(!any.empty())
        {
            int removed = dog.pop_front();
            any.remove_value(removed);
            return removed;
        }
        else exit(1);
    }
};
int main()
{
    Animal_Shelter Animal;
    Animal.enqueue(4);
    Animal.enqueue(6);
    Animal.enqueue(3);
    Animal.enqueue(1);
    Animal.enqueue(12);
    Animal.enqueue(5);
    Animal.enqueue(32);
    Animal.enqueue(16);
    Animal.enqueue(31);
    Animal.enqueue(92);
    Animal.enqueue(15);
    Animal.enqueue(19);
    cout << Animal.dequeueAny() << endl;
    cout << Animal.dequeueCat() << endl;
    cout << Animal.dequeueDog() << endl;
}
