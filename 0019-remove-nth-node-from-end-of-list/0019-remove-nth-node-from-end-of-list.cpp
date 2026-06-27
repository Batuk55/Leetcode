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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL)
            return nullptr;

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if(count == n){//deleting head;
            ListNode* tempHead = head;
            head = head->next;
            delete tempHead;
            return head;
        }

        temp = head;
        int a = count - n;

        while (a > 1) {
            temp = temp->next;
            a--;
        }
        ListNode* prev = temp;
        temp = temp->next;
        prev->next = prev->next->next;
        // temp->next = nullptr; --Once you're deleting temp, you don't care
        // about its next.
        delete temp;

        return head;
    }
};