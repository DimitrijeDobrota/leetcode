// 2657. Find the Prefix Common Array of Two Arrays
class Solution {
  public:
    vector<int> findThePrefixCommonArray(const vector<int> &A, const vector<int> &B) {
        vector<int> res(A.size());
        unordered_set<int> setA, setB;
        for (int i = 0, count = 0; i < A.size(); i++) {
            if (A[i] == B[i])
                count++;
            else {
                if (setB.count(A[i]))
                    count++;
                else
                    setA.insert(A[i]);
                if (setA.count(B[i]))
                    count++;
                else
                    setB.insert(B[i]);
            }
            res[i] = count;
        }
        return res;
    }
};
