class Solution {
  public:
    bool canArrange(const vector<int> &arr, int k) const {
        static int count[100000];

        memset(count, 0x00, sizeof(count));
        for (const int n : arr)
            count[((n % k) + k) % k]++;

        if (count[0] % 2 == 1) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (count[i] != count[k - i]) return false;
        }

        return true;
    }
};
