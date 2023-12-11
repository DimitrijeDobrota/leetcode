class Solution {
  public:
    int findSpecialInteger(vector<int> &arr) {
        const int n = size(arr), quarter = n / 4;
        for (const int candidate : {arr[n / 4], arr[n / 2], arr[3 * n / 4]}) {
            const int left = lower_bound(begin(arr), end(arr), candidate) - begin(arr);
            const int right = upper_bound(begin(arr), end(arr), candidate) - begin(arr);
            if (right - left > quarter) return candidate;
        }
        return -1;
    }
};
