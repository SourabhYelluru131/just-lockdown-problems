//      Implementation of Linked List
#include <iostream>
using namespace std;
//      length()            ->      return length of linked list
//      empty()             ->      returns true if linked list is empty, else returns false
//      value_at(ind)       ->      return value at the given index
//      push_front(value)   ->      inserts element at the beginning of the linked list
//      pop_front           ->      removes the first element and also returns the value that was removed
//      push_back(value)    ->      inserts element at the end of the linked list
//      pop_back()          ->      returns the last element of the linked list and returns the value that was removed
//      front()             ->      returns the first element     O(1)
//      back()              ->      returns the last element      O(n)
//      insert(index,value) ->      inserts node with the given value at the given index
//      erase(index)        ->      erases the element at given index.
//      value_n_from_end(n) ->      returns value of node at nth position from end. Note- Not nth index from end
//      remove_value(value) ->      removes the first instance of the value from the linked list if it exists
/*       ToDo:
 reverse() - reverses the list
 */
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
    int length()
    {
        return size;
    }
    bool empty()
    {
        if(!size) return true;
        return false;
    }
    int value_at(int index)
    {
        if(size<=index || head==NULL) exit(1);
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
        if(head==NULL) exit(1);             // If there is no element, head is NULL, so do nothing
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
    int pop_back()
    {
        if(head==NULL) exit(1);
        if(size==1){
            int a = head->data;
            head=NULL;
            size--;
            return a;
        }
        Node *current = head;
        for(int i=0;i<size-2;i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = NULL;
        size--;
        return temp->data;
    }
    int front()
    {
        if(head==NULL) exit(1);
        return head->data;
    }
    int back()
    {
        if(head==NULL) exit(1);
        Node *current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        return current->data;
    }
    void insert(int index, int value)
    {
        Node* temp = new Node();
        temp->data = value;
        if(head==NULL)
        {
            head = temp;
            temp->next = NULL;
            size++;
            return;
        }
        if(index==0)
        {
            temp->next = head->next;
        }
        Node *current = head;
        for(int i=0;i<index-1;i++)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
        size++;
    }
    void erase(int index)
    {
        if(size<=index || head==NULL) return;
        if(index==0)
        {
            head = head->next;
            size--;
            return;
        }
        Node *current = head;
        Node *after = head->next;
        for(int i=0;i<index-1;i++)
        {
            current = after;          //index i
            after = after->next;      //index i+1
        }
        current->next = after->next;            //node at index-1 points to index+1, NULL if index previously pointing at NULL
        size--;
        return;
    }
    int value_n_from_end(int n)
    {
        if(head==NULL) exit(1);
        if(size<n) exit(1);
        int ind = size-n;
        Node *current = head;
        for(int i=0;i<ind;i++)
        {
            current=current->next;
        }
        return current->data;
    }
    void remove_value(int value)
    {
        if(head==NULL) return;
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
int main()
{
    Linked_List list; // Instantiating an object of class Linked_List
    cout << list.empty() << endl;
    list.push_back(3);
    cout << list.empty() << endl;
    list.push_front(2);
    list.push_back(4);
    cout << list.pop_front() << endl;
    cout << list.pop_back() << endl;
    list.push_front(5);
    list.push_back(3);
    list.push_back(12);
    list.push_back(9);
    list.push_back(7);
    list.push_front(4);
    list.push_back(17);
    cout << list.front() << endl;
    cout << list.back() << endl;
    list.print();
}
