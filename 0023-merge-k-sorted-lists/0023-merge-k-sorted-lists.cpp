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
ListNode* merge2lists(ListNode* list1,ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        while(list1!=NULL && list2!=NULL){

            if(list1->val < list2->val){
                res->next = list1;
                res = res->next; //res = list1;
                list1 = list1->next;
            }
            else{
                res->next = list2;
                res = res->next; //res = list2;
                list2 = list2->next;
            }
        }
        if(list1) res->next = list1;
        if(list2) res->next = list2;

        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(head == NULL || head->next == NULL) return head;

        //    ListNode* mergedHead = flattenLinkedList(head->next);
            if (lists.empty() == true) return NULL;
            if (lists.size() == 1) return lists[0];

            // int n = lists.size();
            ListNode* mergedlist = NULL;

            for(int i = 0; i<lists.size(); i++){
                mergedlist =  merge2lists(mergedlist, lists[i]);

            }
            return mergedlist;

        
    }
};