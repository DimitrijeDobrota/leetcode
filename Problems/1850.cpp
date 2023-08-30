class Solution {
  public:
    int getMinSwaps(string &num, int k) {
        string perm = num;
        while (k--)
            next_permutation(perm.begin(), perm.end());

        int res = 0;
        for (int i = 0, j = 0; i < num.size(); j = ++i) {
            while (num[j++] != perm[i])
                ;
            res += j - i - 1;
            while (i < --j)
                swap(num[j], num[j - 1]);
        }
        return res;
    }
};
