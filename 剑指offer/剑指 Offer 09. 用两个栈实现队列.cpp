class CQueue {
private:
    stack<int> inst, outst;
public:
    void in2out(){
        while(!inst.empty()){
            outst.push(inst.top());
            inst.pop();
        }
    }

    CQueue() {
    }
    
    void appendTail(int value) {
        inst.push(value);
    }
    
    int deleteHead() {
        if (outst.empty()){
            if (inst.empty()) return -1;
            else in2out();
        }
        int ret = outst.top();
        outst.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */