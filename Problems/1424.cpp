class Solution {
    typedef tuple<int, int, int> rec_t;

  public:
    vector<int> findDiagonalOrder(const vector<vector<int>> &nums) const {
        static rec_t arr[100001];
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                arr[n++] = {-i - j, i, nums[i][j]};
            }
        }
        sort(begin(arr), begin(arr) + n, greater<rec_t>());
        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(get<2>(arr[i]));
        return res;
    }
};
