/*
The link to the problem: https://leetcode.com/problems/add-two-numbers/
*/

/*
 * Results:
 * Runtime: 86 ms, faster than 10.76% of C++ online submissions for Add Two
 * Numbers. Memory Usage: 71.4 MB, less than 82.32% of C++ online submissions
 * for Add Two Numbers.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* sum = nullptr;
    bool carry = false;

    while (l1 != nullptr || l2 != nullptr) {
      int value = carry ? 1 : 0;
      carry = false;

      if (l1 != nullptr) {
        value = value + l1->val;
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        value = value + l2->val;
        l2 = l2->next;
      }

      if (value > 10) {
        value = value - 10;
        carry = true;
      }

      ListNode* digit = new ListNode(value);

      if (sum == nullptr) {
        sum = digit;
        head = sum;
      } else {
        sum->next = digit;
        sum = sum->next;
      }
    }

    if (carry) {
      ListNode* digit = new ListNode(1);
      sum->next = digit;
    }

    return head;
  }
};