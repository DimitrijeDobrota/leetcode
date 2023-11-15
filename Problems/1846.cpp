class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging(const vector<int> &arr) const {
        static int count[100001];
        memset(count, 0x00, sizeof(count));

        const int n = size(arr);
        for (const int num : arr)
            count[min(num, n)]++;

        int res = 1;
        for (int num = 2; num <= n; num++) {
            res = min(res + count[num], num);
        }
        return res;
    }
};
