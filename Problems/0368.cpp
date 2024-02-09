class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) const {
        sort(begin(nums), end(nums));

        static int len[1001], parent[1001];
        memset(len, 0x00, sizeof(len));

        int maxi = 0, idx = -1;
        for (int i = size(nums) - 1; i >= 0; i--) {
            for (int j = i; j < size(nums); j++) {
                if (nums[j] % nums[i] == 0 && len[i] < 1 + len[j]) {
                    len[i] = 1 + len[j];
                    parent[i] = j;

                    if (len[i] > maxi) {
                        maxi = len[i];
                        idx = i;
                    }
                }
            }
        }

        vector<int> res(maxi);
        for (int i = 0; i < maxi; i++) {
            res[i] = nums[idx];
            idx = parent[idx];
        }

        return res;
    }
};
