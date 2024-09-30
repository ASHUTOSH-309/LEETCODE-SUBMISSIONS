#include<bits/stdc++.h>
#include<algorithm>


class CustomStack {
private:
    vector<int> MyCustomStack;
    int top;
    int size;

public:
    CustomStack(int maxSize) {
        top = -1;
        size = maxSize;
    }

    void push(int x) {
        if (MyCustomStack.size() < size) {
            MyCustomStack.push_back(x);
            top++;
        }
    }

    int pop() {
        // Pop only if stack is not empty
        if (!MyCustomStack.empty()){
            int val=MyCustomStack.back();
            MyCustomStack.pop_back();
            top--;
            return val;
        }
    
            return -1;
        
    }

    void increment(int k, int val) {

            // Increment the first `k` elements by `val`, or all elements if `k` exceeds current size
        int limit = min(k, (int)MyCustomStack.size());  // Get the smaller of k or stack size
        for (int i = 0; i < limit; ++i) {
            MyCustomStack[i] += val;
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */