// Declare an array of particular size.
// Define a variable “Top” and initialize it as -1.
// push(x): insert element is the array by increasing top by one.
// pop(): check whether top is not equal to -1 if it is so, return top and decrease its value by one.
// size(): return top+1.

#include <bits/stdc++.h>

using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};
int main()
{

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}