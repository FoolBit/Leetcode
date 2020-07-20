/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
        ListNode* p = l1;
        while(1)
        {
            if(l2 == NULL)
                l2 = new ListNode(0);

            l1->val = l1->val + l2->val + x;
            x = l1->val / 10;
            l1->val %= 10;

            if(l2->next != NULL || x != 0)
            {
                if(l1->next == NULL)
                    l1->next = new ListNode(0);
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }

            break;
        }

        return p;
    }
};