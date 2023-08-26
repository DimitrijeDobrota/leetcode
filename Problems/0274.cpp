class Solution {
    static int arr[5001];

  public:
    int hIndex(vector<int> &citations) {
        memset(arr, 0x00, sizeof(arr));
        for (int n : citations)
            arr[n]++;

        int total = 0;
        for (int i = 5000; i >= 0; i--) {
            total += arr[i];
            if (total >= i) return i;
        }

        return -1;
    }
};

int Solution::arr[5001] = {0};
