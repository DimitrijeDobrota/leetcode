class Solution {
  public:
    string countAndSay(int n) {
        string crnt = "1";
        for (int i = 1; i < n; i++) {
            string res = "";
            int c = crnt.front(), count = 1;
            for (int i = 1; i < crnt.size(); i++) {
                if (crnt[i] == c)
                    count++;
                else {
                    res += to_string(count) + (char)c;
                    count = 1;
                    c = crnt[i];
                }
            }
            crnt = res + to_string(count) + (char)c;
        }
        return crnt;
    }
};
