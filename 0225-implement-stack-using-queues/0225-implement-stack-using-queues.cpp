class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if (q1.empty()) {
            return -1;
        }
         while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q1.pop();
        swap(q1, q2);
        return topElement;
    }
    
    int top() {
        if (q1.empty()) {
            return -1; 
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */