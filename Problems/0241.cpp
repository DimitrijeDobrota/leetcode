class Solution {
    int operate(char op, int a, int b) {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        }
        return 0;
    }

    vector<int> rec(const string &expression, int start, int end) {
        vector<int> res;
        for (int i = start; i < end; i++) {
            if (isdigit(expression[i])) continue;
            for (auto n1 : rec(expression, start, i))
                for (auto n2 : rec(expression, i + 1, end))
                    res.push_back(operate(expression[i], n1, n2));
        }
        if (res.empty()) return {stoi(expression.substr(start, end - start))};
        return res;
    }

  public:
    vector<int> diffWaysToCompute(const string &expression) { return rec(expression, 0, expression.size()); }
};
