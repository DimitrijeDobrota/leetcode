class Solution {
  public:
    string largestNumber(const vector<int> &nums) {
        const static auto cmp = [](const string &x, const string &y) { return x + y > y + x; };

        vector<string> v(nums.size());
        for (int i = 0; i < v.size(); i++)
            v[i] = to_string(nums[i]);

        sort(v.begin(), v.end(), cmp);
        if (v[0] == "0") return "0";

        string res = "";
        for (int i = 0; i < v.size(); i++)
            res += v[i];
        return res;
    }
};
