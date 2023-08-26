class Solution {
  public:
    vector<int> maxDepthAfterSplit(const string &seq) {
        vector<int> res;
        res.reserve(seq.size());
        for (int i = 0, count = 0; i < seq.size(); i++) {
            if (seq[i] == '(') count++;
            res.push_back(count % 2);
            if (seq[i] == ')') count--;
        }
        return res;
    }
};
