// Solution 1: time O(n); space O(n)
class Solution {
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for (auto num : s1)
            if (!s2.count(num)) res[0].push_back(num);
        for (auto num : s2)
            if (!s1.count(num)) res[1].push_back(num);
        return res;
    }
};

// Solution 2: time O(nlogn); space O(1)
class Solution {
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res(2);

        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            while (i < nums1.size() - 1 && nums1[i] == nums1[i + 1])
                i++;
            while (j < nums2.size() - 1 && nums2[j] == nums2[j + 1])
                j++;

            if (i >= nums1.size() || j >= nums2.size())
                break;
            else if (nums1[i] < nums2[j])
                res[0].push_back(nums1[i++]);
            else if (nums1[i] > nums2[j])
                res[1].push_back(nums2[j++]);
            else
                i++, j++;
        }

        while (i < nums1.size()) {
            res[0].push_back(nums1[i]);
            while (++i < nums1.size() && nums1[i - 1] == nums1[i])
                ;
        }

        while (j < nums2.size()) {
            res[1].push_back(nums2[j]);
            while (++j < nums2.size() && nums2[j - 1] == nums2[j])
                ;
        }

        return res;
    }
};

// Solution 3: time O(1); space O(n)
class Solution {
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res(2);

        bitset<2002> bs1, bs2;
        for (auto num : nums1)
            bs1.set(num + 1000);
        for (auto num : nums2)
            bs2.set(num + 1000);

        for (int i = 0; i < 2002; i++) {
            if (bs1[i] && bs2[i])
                continue;
            else if (bs1[i])
                res[0].push_back(i - 1000);
            else if (bs2[i])
                res[1].push_back(i - 1000);
        }

        return res;
        O
    }
};
