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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        vector<ListNode*> arr;

        ListNode * temp = head;
        while(temp != nullptr){
            // cout << temp->val;
            arr.push_back(temp);
            temp = temp->next;
        }
        
        //ListNode* newtemp = 
        for(int i = arr.size() - 1; i > 0 ; i--){
            arr[i] -> next = arr[i-1];
        }
        arr[0]->next =  nullptr;


        return arr.back();
    }
};