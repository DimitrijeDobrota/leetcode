class Solution {
  public:
    int arrayNesting(const vector<int> &nums) const {
        static int seen[100001];

        const int n = size(nums);
        memset(seen, 0x00, n * sizeof(int));

        int res = 0;
        for (int i = 0; i < size(nums); i++) {
            int crnt = i, size = 0;
            while (!seen[crnt])
                size++, seen[crnt] = true, crnt = nums[crnt];
            res = max(res, size);
        }
        return res;
    }
};
