/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
     struct ListNode d;
     d.next=NULL;
     struct ListNode *t;
     t=&d;
     int c=0;
     while((l1!=NULL)||(l2!=NULL)||c!=0){
        struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=c;
        c=sum/10;
       int n=sum%10;
        node->val=n;
        node->next=NULL;
        t->next=node;
        t=node;

     }
     return d.next;
}