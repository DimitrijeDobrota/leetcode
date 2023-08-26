class Solution {
  public:
    int largestVariance(const string &s) {
        int count[27] = {0}, res = 0;
        for (char c : s)
            count[c & 0xF]++;

        for (char ma = 'a'; ma <= 'z'; ma++) {
            for (char mi = 'a'; mi <= 'z'; mi++) {
                if (ma == mi || !count[ma & 0xF] || !count[mi & 0xF]) continue;
                int mac = 0, mic = 0, rst = count[mi & 0xF];
                for (char c : s) {
                    if (c == ma)
                        mac++;
                    else if (c == mi)
                        mic++, rst--;

                    if (mic > 0) res = max(res, mac - mic);
                    if (mac < mic && rst > 0) mac = mic = 0;
                }
            }
        }
        return res;
    }
};
