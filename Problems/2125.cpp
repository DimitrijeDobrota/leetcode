class Solution {
public:
    int numberOfBeams(const vector<string>& bank) const {
        int res = 0, prev = 0;
        for(const auto& floor: bank) {
            int cnt = 0;
            for(const char c: floor) cnt += c == '1';
            if(cnt) res += cnt * prev, prev = cnt;
        }
        return res;
    }
};
