//  Building Resizable Array i.e. Vector Class from scratch
//  contains:
//      push(elem)            -> append
//      insert(elem, index)   -> insert at element
//      replace(elem,index)   -> replaces new data instead of old
//      at(index)             -> returns element at index
//      pop()                 -> deletes last element
//      size()                -> returns size of vector
//      get_capacity()        -> Returns total capacity of Vector
//      is_empty()            -> Returns true if empty, and false if not
//      find(elem)            -> Return first index of element if present, else -1
//      del(elem)             -> Deleted at particular index
//      rem(elem)             -> Removes all instances of element
// toDo: resize()
#include <iostream>
using namespace std;
class VectorClass
{
    int *arr;
    int capacity; //Total possible storage
    int current; // Current elements
public:
    VectorClass()
    {
        // Initializing
        arr = new int[1];
        capacity = 1;
        current = 0;
    }
    void push(int data)
    {
        if(current==capacity)
        {
            int *temp = new int[2*capacity];      // Doubles capacity if capacity limit is reached
            for(int i=0;i<capacity;i++)
            {
                temp[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = temp;                //arr capacity has now been increased
        }
        arr[current] = data;
        current++;
    }
    void insert(int data, int index)
    {
        if(index==current)
        {
            push(data);
        }
        else
        {
            push(arr[current-1]);
            int tempo = data;
            for(int i=index;i<current-1;i++)
            {
                int tempo2 = arr[i];
                arr[i] = tempo;
                tempo = tempo2;
            }
        }
    }
    void replace(int data, int index)
    {
        if(index<current)
        {
            arr[index] = data;
        }
    }
    int at(int index)
    {
        if(index<current)
        {
            return arr[index];
        }
    }
    void pop()
    {
        current--;          // Very clever, deny access xD
    }
    int size()
    {
        return current;
    }
    int get_capacity()
    {
        return capacity;
    }
    bool is_empty()
    {
        if(current>0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int find(int data)
    {
        int index = -1,flag = 0,i;
        for(i=0;i<capacity;i++)
        {
            if(arr[i]==data)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            index = i;
        }
        return index;
    }
    void del(int index)
    {
        for(int i=index;i<current-1;i++)
        {
            arr[i]=arr[i+1];
        }
        current--;
    }
    void rem(int data)
    {
        for(int i=0;i<current;i++)
        {
            if(arr[i]==data)
            {
                del(i);
                i--;
                current--;
            }
        }
    }
    void print()
    {
        for(int i=0;i<current;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
