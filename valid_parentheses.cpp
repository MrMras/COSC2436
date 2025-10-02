struct node{
    char c;
    node* next;
    node(char c):c(c), next(nullptr) {}
    node(char c, node* next):c(c), next(next) {}
};

class mystack {
private:
    node* head = nullptr;
public:
    void push(char c) {
        node* cu = new node(c, head);
        head = cu;
    }
    bool pop(char& p) {
        if (head==nullptr)
            return false;
        p = head->c;
        node* tmp = head->next;
        delete head;
        head = tmp;
        return true;
    }
};


class Solution {
public:
    bool isValid(string s) {
        mystack st;
        char last;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else {
                if (st.pop(last)) {
                    if (last == '{' && s[i] == '}' || 
                    last == '(' && s[i] == ')' ||
                    last == '[' && s[i] == ']') continue;
                }
                return false;
            }
        }

        return !st.pop(last);
    }
};
