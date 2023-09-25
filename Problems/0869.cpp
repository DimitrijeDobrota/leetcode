class Solution {
    static const unordered_set<string> cache;

  public:
    bool reorderedPowerOf2(int n) {
        string digits;
        do {
            digits.push_back('0' + n % 10);
        } while ((n /= 10) > 0);

        sort(begin(digits), end(digits));
        return cache.count(digits);
    }
};

const unordered_set<string> Solution::cache = {
    "1",        "2",        "4",        "8",         "16",        "23",       "46",      "128",
    "256",      "125",      "0124",     "0248",      "0469",      "1289",     "13468",   "23678",
    "35566",    "011237",   "122446",   "224588",    "0145678",   "0122579",  "0134449", "0368888",
    "11266777", "23334455", "01466788", "112234778", "234455668", "012356789"};
