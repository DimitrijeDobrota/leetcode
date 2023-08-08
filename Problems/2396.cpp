class Solution {
public:
    bool isStrictlyPalindromic(int n) { return false; }
};

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string s = "";
        for(int base = n - 2, crnt = n; base >= 2; base--, crnt=n) {
            s.clear();
            do {
                s+='0' + crnt%base;
            } while((crnt /= base) > 0);
            int i = 0, j=s.size() - 1;
            while(i < j) if(s[i++] != s[j--]) return false;
        }

        return true;
    }
};
