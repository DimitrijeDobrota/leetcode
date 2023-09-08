class Solution {
  public:
    string minimizeResult(const string &expression) {
        const int idx = expression.find('+');
        const string a = expression.substr(0, idx);
        const string b = expression.substr(idx + 1);

        int mini = INT_MAX, mi, mj;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                int out = (i != 0 ? stoi(a.substr(0, i)) : 1) * (j != b.size() ? stoi(b.substr(j)) : 1);
                int in = stoi(a.substr(i)) + stoi(b.substr(0, j));
                if (in * out < mini) {
                    mini = in * out;
                    mi = i;
                    mj = j;
                }
            }
        }

        return a.substr(0, mi) + "(" + a.substr(mi) + "+" + b.substr(0, mj) + ")" + b.substr(mj);
        ;
    }
};
