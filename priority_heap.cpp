/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   struct cmp{
        bool operator()(const ListNode* lhs,const ListNode* rhs){
            return lhs->val > rhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> num;
        ListNode head(0);
        ListNode*cur=&head,*tem=NULL;
        for(int i=0;i<lists.size();++i){
            if(lists[i]!=NULL) num.push(lists[i]);
        }
        while(!num.empty()){
            tem=num.top();
            num.pop();
            cur->next=tem;
            cur=cur->next;
            if(tem->next!=NULL) num.push(tem->next);
        }
        return head.next;
    }
};