//		CTCI Chapter 3 Stacks And Queues Problem 8
//			Queues using 2 Stacks
//	https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
private:
        stack<int> inStack;
        stack<int> outStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                int a = inStack.top();
                inStack.pop();
                outStack.push(a);
            }
        }
        int a = outStack.top();
        outStack.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        if(outStack.empty()){
            while(!inStack.empty()){
                int a = inStack.top();
                inStack.pop();
                outStack.push(a);
            }
        }
        return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (outStack.empty() && inStack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
