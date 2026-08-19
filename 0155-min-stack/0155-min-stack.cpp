class MinStack {
public:
    stack<long long>st;
    long long minimum=NULL;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minimum=value;
        }
        else if(!st.empty() && value<minimum){
            long long val=2LL*value-minimum;
            st.push(val);
            minimum=value;
        }
        else{
            st.push(value);
        }
    }
    
    void pop() {
        if(st.empty()){return;}
        long long x=st.top();
        if(x<minimum){
            st.pop();
            minimum=2*minimum-x;
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        long long y=st.top();
        if(y<minimum){
            return minimum;
        }
        return y;
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */