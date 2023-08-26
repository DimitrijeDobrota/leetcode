class Solution {
  public:
    vector<int> replaceElements(vector<int> &arr) {
        int maxi = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, tmp);
        }
        return arr;
    }
};
