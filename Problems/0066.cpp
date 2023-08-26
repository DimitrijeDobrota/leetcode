class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;

        int add = 1;
        for (int i = digits.size() - 1; i >= 0 || add; i--) {
            if (i >= 0) add += digits[i];
            res.push_back(add % 10);
            add /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
