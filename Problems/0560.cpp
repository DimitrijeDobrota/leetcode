class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) const {
        unordered_map<int, int> freq{{0, 1}};
        freq.reserve(std::size(nums) + 1);

        int result = 0;
        int prefix = 0;
        for (const auto num: nums) {
            prefix += num;
            if (const auto it = freq.find(prefix - k); it != std::end(freq)) {
                result += it->second;
            }
            freq[prefix]++;
        }

        return result;
    }
};