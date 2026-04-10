class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                s.push(stoi(token));
            } else {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                switch(token[0]) {
                    case '+': 
                        s.push(op1 + op2); 
                        break;
                    case '-':
                        s.push(op2 - op1);
                        break;
                    case '*':
                        s.push(op2 * op1);
                        break;
                    case '/':
                        s.push(op2 / op1);
                        break;
                }
            }
            
        }
        return s.top();
    }
};
