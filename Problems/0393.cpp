class Solution {
  public:
    bool validUtf8(const vector<int> &data) const {
        static const uint8_t mask[] = {0x80, 0xE0, 0xF0, 0xF8};
        static const uint8_t val[] = {0x00, 0xC0, 0xE0, 0xF0};
        const int n = size(data);

        for (int i = 0, j, k; i < n; i++) {
            for (j = 0; j < 4; j++) {
                if ((data[i] & mask[j]) != val[j]) continue;
                break;
            }
            if (j == 4) return false;

            for (k = 0; k < j && i + 1 < n; k++) {
                if ((data[++i] & 0xC0) != 0x80) return false;
            }
            if (k != j) return false;
        }

        return true;
    }
};
