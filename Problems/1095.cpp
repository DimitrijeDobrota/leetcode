class Solution {
    int find_peak(MountainArray &mountainArr) {
        int left = 1, right = mountainArr.length() - 2;
        while (left != right) {
            const int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int find_left(MountainArray &mountainArr, int left, int right, int target) {
        while (left != right) {
            const int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int find_right(MountainArray &mountainArr, int left, int right, int target) {
        while (left != right) {
            const int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) > target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

  public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int peak = find_peak(mountainArr);

        const int left = find_left(mountainArr, 0, peak, target);
        if (mountainArr.get(left) == target) return left;

        const int right = find_right(mountainArr, peak + 1, mountainArr.length() - 1, target);
        if (mountainArr.get(right) == target) return right;

        return -1;
    }
};
