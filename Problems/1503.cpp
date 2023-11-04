class Solution {
  public:
    int getLastMoment(int n, const vector<int> &left, const vector<int> &right) const {
        int l = 0, r = 0;
        if (!left.empty()) l = *max_element(begin(left), end(left));
        if (!right.empty()) r = n - *min_element(begin(right), end(right));
        return max(l, r);
    }
};
