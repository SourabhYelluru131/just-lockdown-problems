//		CTCI Chapter 3 Problem 5
//			Sorted Stack
#include <iostream>
#include <stack>
using namespace std;
void addtoStack(stack<int>& us,stack<int>& ss)
{
    int a = us.top();
    us.pop();
    if(ss.empty() || ss.top()>a)
    {
        ss.push(a);
    }
    else
    {
        stack<int> temp;
        while(ss.top()<a)
        {
            int b = ss.top();
            temp.push(b);
            ss.pop();
            if(ss.empty()) break;
        }
        ss.push(a);
        while(!(temp.empty()))
        {
            int b = temp.top();
            ss.push(b);
            temp.pop();
        }
    }
    if(!us.empty()) addtoStack(us, ss);
    return;
}
int main()
{
    stack<int> sorted, unsorted;
    unsorted.push(6);
    unsorted.push(3);
    unsorted.push(2);
    unsorted.push(5);
    unsorted.push(1);
    unsorted.push(4);
    addtoStack(unsorted, sorted);
    while(!sorted.empty())
    {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;
}
