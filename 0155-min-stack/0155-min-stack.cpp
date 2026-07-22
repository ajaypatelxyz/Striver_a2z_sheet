class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            pair<int, int>p;
            p.first = value;
            p.second = value;
            st.push_back(p);
        }else{
            pair<int, int> p;
            p.first = value;
            int prevMin = st.back().second;
            p.second = min(prevMin, value);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int, int> p = st.back();
        return p.first;
    }
    
    int getMin() {
        pair<int, int> p = st.back();
        return p.second;
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