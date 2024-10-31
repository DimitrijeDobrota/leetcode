class Solution {
  public:
    bool isValidSerialization(const string &preorder) const {
        const int n = size(preorder);
        int size = 1;

        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') continue;
            size--;
            if (size < 0) return false;
            if (preorder[i] != '#') {
                while (i < n && preorder[i + 1] != ',')
                    i++;
                size += 2;
            }
        }

        return size == 0;
    }
};
