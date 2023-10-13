class Solution {
  public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        const int half = (arr.size() - 1) / 2;
        nth_element(begin(arr), begin(arr) + half, end(arr));
        const int median = arr[half];
        nth_element(begin(arr), begin(arr) + k, end(arr), [&](int a, int b) {
            return abs(a - median) != abs(b - median) ? abs(a - median) > abs(b - median) : a > b;
        });
        arr.resize(k);
        return arr;
    }
};

// Two pointer
class Solution {
  public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        sort(begin(arr), end(arr));
        const int median = arr[(arr.size() - 1) / 2];
        int i = 0, j = arr.size() - 1;
        while (k--)
            if (median - arr[i] > arr[j] - median)
                i++;
            else
                j--;
        arr.erase(begin(arr) + i, begin(arr) + j + 1);
        return arr;
    }
};
