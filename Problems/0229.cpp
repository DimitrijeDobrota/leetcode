class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int a = -1, b = -1, ca = 0, cb = 0;
        for (const int n : nums) {
            if (n == a)
                ca++;
            else if (b == n)
                cb++;
            else if (!ca)
                a = n, ca = 1;
            else if (!cb)
                b = n, cb = 1;
            else
                ca--, cb--;
        }
        ca = cb = 0;
        for (const int n : nums) {
            if (n == a)
                ca++;
            else if (n == b)
                cb++;
        }

        vector<int> res;
        if (ca > nums.size() / 3) res.push_back(a);
        if (cb > nums.size() / 3) res.push_back(b);
        return res;
    }
};
