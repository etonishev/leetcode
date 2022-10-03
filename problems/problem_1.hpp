/*
The link to the problem: https://leetcode.com/problems/two-sum/
*/

#include <map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, std::size_t> hashTable;

    for (std::size_t i = 0; i < nums.size(); ++i) {
      auto it = hashTable.find(target - nums[i]);
      if (it != hashTable.end()) {
        return {static_cast<int>(it->second), static_cast<int>(i)};
      }

      hashTable.insert(std::make_pair(nums[i], i));
    }

    return {};
  }
};