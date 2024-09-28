class Solution {
  public:
    string decodeCiphertext(const string &encodedText, int rows) const {
        const int col = size(encodedText) / rows;
        string res;

        for (int i = 0; i < col; i++) {
            for (int j = i; j < size(encodedText); j += (col + 1)) {
                res += encodedText[j];
            }
        }

        while (!res.empty() && res.back() == ' ')
            res.pop_back();

        return res;
    }
};
