class Solution {
  public:
    bool parseBoolExpr(const string &expression) const {
        bool state = false;
        stack<char> op;

        const auto flush = [&](int &i) {
            for (int count = 0; i < size(expression); i++) {
                if (expression[i] == '(')
                    count++;
                else if (expression[i] == ')' && count-- == 0)
                    break;
            }
            op.pop();
        };

        for (int i = 0; i < size(expression); i++) {
            switch (expression[i]) {
            case 't': state = true; break;
            case 'f': state = false; break;
            case '!':
            case '&':
            case '|': op.push(expression[i]); break;
            case ',':
                // lazy evaluation
                switch (op.top()) {
                case '&':
                    if (!state) flush(i);
                    break;
                case '|':
                    if (state) flush(i);
                    break;
                }
                break;
            case ')':
                if (op.top() == '!') state = !state;

                op.pop();
                break;
            }
        }

        return state;
    }
};
