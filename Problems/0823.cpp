class Solution {
    static const int MOD = 1E9 + 7;

    static int binary_search(const vector<int> &arr, const int end, const int target) {
        int low = 0, high = end - 1;
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

  public:
    int numFactoredBinaryTrees(vector<int> &arr) const {
        static int mem[1000];
        memset(mem, 0x00, sizeof(mem));

        sort(begin(arr), end(arr));
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            const int crnt = arr[i];
            long long local = 1;
            for (int j = 0; j < i; j++) {
                if (crnt % arr[j] != 0) continue;
                const int idx = binary_search(arr, i, crnt / arr[j]);
                if (idx == -1) continue;
                local = (local + (long long)mem[j] * mem[idx]) % MOD;
            }
            mem[i] = local;
            res = (res + mem[i]) % MOD;
        }
        return res;
    }
};
