class Solution {
    vector<int> vec;
    const string chars;
    string res;

    bool has_next = true;
    void shuffle() {
        int goal = chars.size() - 1, idx = vec.size() - 1;
        while (idx > 0 && vec[idx] == goal)
            goal--, idx--;
        for (int i = idx, acc = vec[idx]; i < vec.size(); i++)
            res[i] = chars[vec[i] = ++acc];
        if (idx == 0 && vec[0] == goal) has_next = false;
    }

  public:
    CombinationIterator(string chars, int len) : chars(chars), vec(len), res(len, ' ') {
        for (int i = 0; i < len; i++)
            res[i] = chars[vec[i] = i];
        vec.back()--;
    }

    string next() {
        shuffle();
        return res;
    }

    bool hasNext() { return has_next; }
};
