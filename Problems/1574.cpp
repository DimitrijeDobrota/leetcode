class Solution {
  public:
    int findLengthOfShortestSubarray(const vector<int> &arr) const {
        const int n = size(arr);
        int i = 0, j = n - 1;

        while (i + 1 < n && arr[i] <= arr[i + 1])
            i++;
        if (i == n - 1) return 0;

        while (j > i && arr[j - 1] <= arr[j])
            j--;

        int res = min(n - i - 1, j);
        for (int k = 0; k <= i && j < n;) {
            if (arr[j] >= arr[k])
                res = min(res, j - k++ - 1);
            else
                j++;
        }

        return res;
    }
};
