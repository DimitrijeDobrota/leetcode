class Solution {
  public:
    vector<int> findClosestElements(const vector<int> &arr, int k, int x) const {
        const int n = size(arr);

        const auto mid = upper_bound(begin(arr), end(arr), x);
        if (mid == end(arr)) return vector(begin(arr) + n - k, end(arr));

        int j = distance(begin(arr), mid), i = j - 1;
        int a = 0, b = k - 1;
        vector<int> res(k);

        while (a <= b) {
            if (j < n && (i < 0 || x - arr[i] > arr[j] - x))
                res[b--] = arr[j++];
            else
                res[a++] = arr[i--];
        }

        reverse(begin(res), begin(res) + a);
        reverse(begin(res) + b + 1, end(res));

        return res;
    }
};
