class Solution {
  public:
    int numSubarraysWithSum(const vector<int> &nums, int goal) const {
        unordered_map<int, int> um = {{0, 1}};
        int res = 0, crnt = 0;

        for (const int n : nums) {
            crnt += n;
            res += um[crnt - goal];
            um[crnt]++;
        }

        return res;
    }
};

// O(1) space
class Solution {
    int atMost(const vector<int> &nums, int goal) const {
        if (goal < 0) return 0;

        int res = 0, crnt = 0, i = 0;
        for (int j = 0; j < size(nums); j++) {
            goal -= nums[j];
            while (goal < 0)
                goal += nums[i++];
            res += j - i + 1;
        }

        return res;
    }

  public:
    int numSubarraysWithSum(const vector<int> &nums, int goal) const {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
