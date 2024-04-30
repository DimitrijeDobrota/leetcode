class Solution {

  public:
    long long wonderfulSubstrings(const string &word) const {

        long long count[1 << 11] = {1}, res = 0;

        uint16_t crnt = 0;

        for (int i = 0; i < size(word); i++) {

            crnt ^= 1 << (word[i] - 'a');

            res += count[crnt];

            for (int j = 0; j < 10; j++) {

                res += count[crnt ^ (1 << j)];
            }

            count[crnt]++;
        }

        return res;
    }
};
