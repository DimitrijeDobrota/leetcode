class Solution {
  public:
    string largestWordCount(const vector<string> &messages, const vector<string> &senders) const {
        unordered_map<string, int> um;
        const int n = size(messages);
        string res;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (const char c : messages[i])
                cnt += c == ' ';
            cnt = um[senders[i]] += cnt + 1;
            if (cnt != maxi ? cnt >= maxi : senders[i] > res) {
                res = senders[i];
                maxi = cnt;
            }
        }
        return res;
    }
};
