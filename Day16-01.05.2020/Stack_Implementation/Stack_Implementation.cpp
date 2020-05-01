//	Implementation of Stack without using arrays
#include<iostream>
using namespace std;
//      push()      ->      Adds element into the stack
//      isEmpty()   ->      returns true if stack is empty, else returns false
//      peek()      ->      Returns the value of the element in the top of the stack
//      pop()       ->      Removes the topmost element of the stack
//      display()   ->      Displays element in the stack from top to bottom


struct StackNode        // basic structure used for creation of stacks. Similar to linked lists.
{
    int data;
    StackNode *next;
};
class Stack
{
public:
    StackNode *top;
    Stack()
    {
        top = nullptr;         //Initialization
    }
    void push(int data)
    {
        struct StackNode *temp = (struct StackNode*)malloc (sizeof (struct StackNode));       //Creating space for new node in the stack
        temp->data = data;
        temp->next = top;
        top = temp;          // inserted node is the new top
    }
    bool isEmpty()
    {
        return top==nullptr;
    }
    int peek()
    {
        if(!top) exit(1);
        return top->data;            //returns top , since LIFO
    }
    void pop()
    {
        if(!top) exit(1);
        StackNode *temp = top->next;
        top = temp;             //next element is now the top
    }
    void display()
    {
        if(!top) exit(1);
        StackNode *current = top;
        while(current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack stack = Stack();
}
