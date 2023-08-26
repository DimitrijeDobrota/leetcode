class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int i = 0, j;
        while (i < words.size()) {
            int count = words[i].size(); // character count
            for (j = i + 1; j < words.size() && count <= maxWidth; j++)
                count += words[j].size() + 1; // word lenght + at least 1 space

            if (count > maxWidth) count -= words[--j].size() + 1; // if we overshot, remove last word
            int wordc = j - i;                                    // number of words for the current row
            count -= wordc - 1;           // remove minimum padding added from the character count;
            int white = maxWidth - count; // how much whitespace
            string row = words[i++];
            if (i != j) {
                if (j != words.size()) {
                    while (i < j) {
                        int segment = ceil((double)white / (wordc-- - 1));
                        row += string(min(segment, white), ' ') + words[i++];
                        white -= segment;
                    }
                } else {
                    // last row, adjust left
                    while (i < j)
                        row += " " + words[i++];
                }
            }
            row += string(maxWidth - row.size(), ' '); // padd the remainder of the row
            res.push_back(row);                        // push the current row to the result
        }
        return res;
    }
};
