class Solution {
  public:
    vector<long long> findPrefixScore(const vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<long long> res(nums.size());
        for (long long i = 0, acc = 0, maxi = 0; i < nums.size(); i++) {
            maxi = max(maxi, (long long)nums[i]);
            res[i] = acc += nums[i] + maxi;
        }
        return res;
    }
};
