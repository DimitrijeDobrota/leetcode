class Solution {
  public:
    int getWinner(vector<int> &arr, int k) const {
        const int n = arr.size();
        const int maxi = *max_element(begin(arr), end(arr));
        if (k >= n) return maxi;

        int crnt = arr[0], count = 0;
        for (int i = 1; i < n; i++) {
            if (crnt > arr[i])
                count++;
            else {
                crnt = arr[i];
                count = 1;
            }
            if (count == k || crnt == maxi) return crnt;
        }

        return maxi;
    }
};
