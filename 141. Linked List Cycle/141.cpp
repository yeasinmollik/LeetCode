/*
    Author: Yeasin Mollik
    Problem Name: 3Sum
    Date: 27/3/2022

*/

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        auto fast = head, slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};
