#define LOG2(X) ((unsigned)(8 * sizeof(int) - __builtin_clz((X)) - 1))

class Solution {
    int flip(int label) {
        int log = LOG2(label), floor = 1 << log, ceil = (1 << log + 1) - 1;
        return floor + ceil - label;
    }

  public:
    vector<int> pathInZigZagTree(int label) {
        bool rev = LOG2(label) % 2;
        vector<int> res({label});
        if (rev) label = flip(label);
        while ((label /= 2) > 0) {
            rev = !rev;
            res.push_back(!rev ? label : flip(label));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
