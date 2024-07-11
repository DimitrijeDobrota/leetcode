class Solution {
  public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x) {
        static int count[100001];
        int sz = 1;

        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != x) continue;
            count[sz++] = i;
        }

        for (auto &query : queries) {
            query = query < sz ? count[query] : -1;
        }

        return queries;
    }
};
