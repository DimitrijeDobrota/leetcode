class Solution {
public:
  double average(vector<int> &salary) {
    int mini = *min_element(salary.begin(), salary.end());
    int maxi = *max_element(salary.begin(), salary.end());
    int sum = 0, count = 0;
    for (int i = 0; i < salary.size(); i++)
      if (salary[i] != mini && salary[i] != maxi) sum += salary[i], count++;

    return (double)sum / count;
  }
};
