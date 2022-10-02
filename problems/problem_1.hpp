#include <map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, std::size_t> map;
    std::vector<int> result;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      int& currentValue = nums[i];
      auto it = map.find(target - currentValue);
      if (it == map.end()) {
        map.insert(std::make_pair(currentValue, i));
      } else {
        result.push_back(it->second);
        result.push_back(i);
        return result;
      }
    }

    return result;
  }
};