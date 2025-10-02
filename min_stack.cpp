struct node {
    node* next;
    int val;
    node(int val, node* next) : val(val), next(next) {}
};

class MinStack {
private:
    node* head;
    node* mins;
public:
    MinStack() {
        head = nullptr;
        mins = nullptr;
    }
    
    void push(int val) {
        node* tmp = new node(val, head);
        head = tmp;
        if (mins == nullptr || mins->val >= val) {
            tmp = new node(val, mins);
                mins = tmp;
        }     
    }
    
    void pop() {
        node* tmp = mins->next;
        if (mins->val == head->val) {
            delete mins;
            mins = tmp;
        }
        tmp = head->next;
        delete head;
        head = tmp;
    }
    
    int top() {
        std::cout << head->val;
        return head->val;
    }
    
    int getMin() {
        std::cout << mins->val;
        return mins->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
