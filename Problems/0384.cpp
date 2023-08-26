class Solution {
    const vector<int> og;
    vector<int> shuffing;

  public:
    Solution(const vector<int> &nums) : og(nums), shuffing(nums) {}

    vector<int> reset() { return og; }

    vector<int> shuffle() {
        random_shuffle(shuffing.begin(), shuffing.end());
        return shuffing;
    }
};
