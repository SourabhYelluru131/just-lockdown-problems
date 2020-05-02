// Implementation of Queue with Array
#include <iostream>
using namespace std;
//      enqueue()       ->      pushes an element into the end of the queue
//      dequeue()       ->      pops the first element of the queue (LIFO)
//      empty()         ->      returns true if queue is empty, else returns false
//      full()          ->      returns true if queue is full, and false if not
// Note - maximum number of elements that can be input to the queue is n-1 where n is the size of the array used to implement this queue
class Queue
{
public:
    int arr[10];
    int read,write;
    Queue()
    {
        this->read=0;
        this->write=0;
    }
    void enqueue(int value)
    {
        if(write+1==read) exit(1);
        arr[write]=value;
        write++;
        write=write%10;                     //Pointer moves back to 0 if at the end of the list
    }
    int dequeue()
    {
        if(read==write) exit(1);
        int ans = arr[read];                //Since LIFO
        read++;
        return ans;
    }
    bool empty()
    {
        return read==write;
    }
    bool full()
    {
        return ((write+1)%10 == read%10);
    }
};
int main()
{
    Queue kyu = Queue();        //Initializing
}


