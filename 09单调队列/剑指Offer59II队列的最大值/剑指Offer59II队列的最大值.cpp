class MaxQueue {
public:
    deque<int> dq;
    vector<int> res;
    int k = 0, end = 0;
    MaxQueue() {
        
    }
    
    int max_value() {
        if(dq.empty()) return -1;
        return res[dq.front()];
    }
    
    void push_back(int value) {
        while(dq.size() && res[dq.back()] <= value) dq.pop_back();
        dq.push_back(end++);
        res.push_back(value);
    }
    
    int pop_front() {
        if(dq.empty()) return -1;
        int t = res[k];
        k++;
        if(dq.front() < k) {
            dq.pop_front();
        }
        return t;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */