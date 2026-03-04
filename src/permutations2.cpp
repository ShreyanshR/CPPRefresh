#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> res;
  unordered_map<int, int> count;

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    for (int &num : nums) {
      count[num]++;
    }

    vector<int> perm;
    dfs(nums, perm);
    return res;
  }

  void dfs(vector<int> &nums, vector<int> &perm) {
    if (perm.size() == nums.size()) {
      res.push_back(perm);
      return;
    }

    for (auto &[num, cnt] : count) {
      if (cnt > 0) {
        perm.push_back(num);
        cnt--;
        cout << "Num: " << num << "count: " << cnt << endl;
        dfs(nums, perm);
        cnt++;
        perm.pop_back();
      }
    }
  }
};