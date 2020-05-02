// Implementation of Queue with Linked Lists
#include <iostream>
using namespace std;
//      enqueue()       ->      pushes an element into the end of the queue
//      dequeue()       ->      pops the first element of the queue (LIFO)
//      empty()         ->      returns true if queue is empty, else returns false
struct QueueNode
{
    int data;
    QueueNode *next;
};
class Queue
{
public:
    QueueNode *head;
    QueueNode *tail;
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void enqueue(int value)
    {
        struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
        temp->data = value;
        temp->next = nullptr;
        if(!head) head = temp;
        if(tail) tail->next = temp;          //if queue is not empty, update the tail's pointer
        tail = temp;                         // tail is always updated while enqueuing
    }
    int dequeue()
    {
        if(!head) exit(1);
        int ans = head->data;                //Since LIFO
        head = head->next;                   //head is always updated during dequeuing
        if(!head) tail = nullptr;            //if last element is being dequeued head is nul, so make tail also null
        return ans;
    }
    bool empty()
    {
        return head==nullptr;
    }
};
int main()
{
    Queue kyu = Queue();        //Initializing
}
