class FindSumPairs {
    unordered_map<int, int> count1, count2;
    vector<int> arr;

  public:
    FindSumPairs(const vector<int> &nums1, const vector<int> &nums2) : arr(nums2) {
        for (const int n : nums1)
            count1[n]++;
        for (const int n : nums2)
            count2[n]++;
    }

    void add(int index, int val) {
        count2[arr[index]]--;
        arr[index] += val;
        count2[arr[index]]++;
    }

    int count(int tot) const {
        int res = 0;

        for (const auto [k, v] : count1) {
            const auto it = count2.find(tot - k);
            if (!v || it == count2.end()) continue;
            res += v * it->second;
        }

        return res;
    }
};
