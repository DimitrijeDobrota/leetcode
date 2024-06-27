class Solution {
  public:
    int minNumberOfFrogs(const string &croakOfFrogs) const {
        static const string word = "croak";
        int count[5] = {0}, frogs = 0, res = 0;

        for (const char c : croakOfFrogs) {
            const int idx = word.find(c);
            if (idx == 0)
                res = max(res, ++frogs);
            else if (!count[idx - 1]--)
                return -1;
            else if (idx == 4)
                frogs--;
            count[idx]++;
        }

        return !frogs ? res : -1;
    }
};
