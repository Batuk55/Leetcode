class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);        
    }
    
    int pop() {
        int a = 0;
        if(!s2.empty()){
            a = s2.top();
            s2.pop();
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            a = s2.top();
            s2.pop();
        }
        return a;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        return 0;     
    }
    
    bool empty() {
        return !(s1.size()|s2.size());      
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