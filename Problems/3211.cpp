class Solution {
  public:
    vector<string> validStrings(int n) {
        vector<string> res = {"0", "1"};

        for (int i = 1; i < n; i++) {
            for (int j = size(res) - 1; j >= 0; j--) {
                if (res[j].back() == '1') res.push_back(res[j] + '0');
                res[j] += '1';
            }
        }

        return res;
    }
};
