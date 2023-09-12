class Solution {
  public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};

        for (int i = 1; i < folder.size(); i++) {
            const string root = res.back() + "/";
            const string prefix = folder[i].substr(0, root.size());
            if (prefix != root) res.push_back(folder[i]);
        }

        return res;
    }
};
