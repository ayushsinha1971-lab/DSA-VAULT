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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode * pre=head;
        ListNode *curr=head->next;
        vector <int> ans(2,-1);
        if(!head||!head->next||!head->next->next)return ans;
        int i=0;
        int f=-1,l=-1,mindis=INT_MAX;

        while(curr->next!=nullptr){
            if((curr->next->val<curr->val&&curr->val>pre->val)||(curr->next->val>curr->val&&curr->val<pre->val)){
                if(f==-1){
                    f=i;
                }
                else{
                    mindis=min(mindis,i-l);
                }
                  l=i;    
            }
          
            i++;
            pre=curr;
            curr=curr->next;
        }
        if(f==-1||f==l){
            return ans;
        }
        ans[1]=l-f;
        ans[0]=mindis;
        
        return ans;
    }
};