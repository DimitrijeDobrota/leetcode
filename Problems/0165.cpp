class Solution {
  public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        vector<int> v1, v2;

        string crnt;
        while (getline(s1, crnt, '.'))
            v1.push_back(stoi(crnt));
        while (getline(s2, crnt, '.'))
            v2.push_back(stoi(crnt));

        while (v1.size() < v2.size())
            v1.push_back(0);
        while (v1.size() > v2.size())
            v2.push_back(0);

        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] > v2[j]) return 1;
            if (v1[i] < v2[j])
                return -1;
            else
                i++, j++;
        }

        return 0;
    }
};
