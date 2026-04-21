class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for (const std::string& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int b = st.top(); st.pop();   // right operand
                int a = st.top(); st.pop();   // left operand
                int result = 0;

                if      (tok == "+") result = a + b;
                else if (tok == "-") result = a - b;
                else if (tok == "*") result = a * b;
                else                 result = a / b;  // truncates toward 0 in C++

                st.push(result);
            } else {
                st.push(std::stoi(tok));
            }
        }

        return st.top();
    }
};
