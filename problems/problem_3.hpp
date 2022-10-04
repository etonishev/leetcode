/*
 * The link to the problem:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

/*
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 */

#include <string>

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    int longestSize = 1;
    std::string substr;

    for (std::size_t i = 0; i < s.size(); ++i) {
      std::size_t where = substr.find(s[i]);
      if (where != std::string::npos) {
        substr.erase(0, where + 1);
      }

      substr.append(1, s[i]);
      if (longestSize < substr.size()) {
        longestSize = substr.size();
      }
    }

    return longestSize;
  }
};