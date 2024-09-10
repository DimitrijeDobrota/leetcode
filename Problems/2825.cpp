class Solution {
  public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;

        while (i < size(str1) && j < size(str2)) {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) {
                i++, j++;
            } else
                i++;
        }

        return j == size(str2);
    }
};
