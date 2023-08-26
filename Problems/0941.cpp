class Solution {
  public:
    bool validMountainArray(vector<int> &arr) {
        int i = 0;
        while (i < arr.size() - 1 && arr[i] < arr[i + 1])
            i++;

        if (i == 0) return false;

        int j = i;
        while (i < arr.size() - 1 && arr[i] > arr[i + 1])
            i++;

        if (i == j) return false;

        return i == arr.size() - 1;
    }
};
