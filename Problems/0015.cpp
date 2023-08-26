class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &num) {
        sort(num.begin(), num.end());

        vector<vector<int>> res;
        for (int i = 0; i < num.size();) {
            int target = -num[i], start = i + 1, end = num.size() - 1;

            while (start < end) {
                int sum = num[start] + num[end];
                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else {
                    res.push_back({num[i], num[start], num[end]});
                    while (start < end && num[start] == res.back()[1])
                        start++;
                    while (start < end && num[end] == res.back()[2])
                        end--;
                }
            }
            for (i++; i < num.size() && num[i] == num[i - 1]; i++)
                ;
        }

        return res;
    }
};
