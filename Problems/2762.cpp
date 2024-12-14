class Solution {
  public:
    long long continuousSubarrays(const vector<int> &nums) const {
        const int n = size(nums);
        long long res = 0;

        map<int, int> mp;
        for (int i = 0, j = 0; j < n; j++) {
            mp[nums[j]]++;

            while (mp.rbegin()->first - mp.begin()->first > 2) {
                const int crnt = nums[i++];
                if (!--mp[crnt]) mp.erase(crnt);
            }

            res += j - i + 1;
        }

        return res;
    }
};
