class Solution {
  public:
    bool isOneBitCharacter(const vector<int> &bits) const {
        int last = -2;

        for (int i = 0; i < size(bits); i++) {
            if (bits[i]) last = i++;
        }

        return last != size(bits) - 2;
    }
};
