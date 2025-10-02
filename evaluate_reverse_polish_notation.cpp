class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> polish;
        int el1, el2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                el1 = polish.top();
                polish.pop();
                el2 = polish.top();
                polish.pop();
                polish.push(el1 + el2);
            }
            else if (tokens[i] == "-") {
                el1 = polish.top();
                polish.pop();
                el2 = polish.top();
                polish.pop();
                polish.push(el2 - el1);
            }
            else if (tokens[i] == "*") {
                el1 = polish.top();
                polish.pop();
                el2 = polish.top();
                polish.pop();
                polish.push(el1 * el2);
            }
            else if (tokens[i] == "/") {
                el1 = polish.top();
                polish.pop();
                el2 = polish.top();
                polish.pop();
                polish.push(el2 / el1);
            }
            else {
                polish.push(std::stoi(tokens[i]));
            }
        }
        return polish.top();
    }
};
