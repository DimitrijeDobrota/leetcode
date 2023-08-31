class Solution {
  public:
    vector<int> pancakeSort(vector<int> &arr) {
        vector<int> res;

        for (int i = arr.size() - 1, low, high; i >= 0; i--) {
            if (arr[i] == i + 1) continue;

            low = 0, high = 0;
            while (arr[high] != i + 1)
                high++;

            res.push_back(high + 1);
            while (low < high)
                swap(arr[low++], arr[high--]);

            low = 0, high = i;
            res.push_back(high + 1);
            while (low < high)
                swap(arr[low++], arr[high--]);
        }
        return res;
    }
};
