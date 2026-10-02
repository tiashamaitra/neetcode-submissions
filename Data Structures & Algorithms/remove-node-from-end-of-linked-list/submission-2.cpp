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
        ListNode *temp=head;
        ListNode *prev=NULL;
        ListNode *pl=NULL;
        int l=0;
        while(temp!=NULL)
        {
            l=l+1;
            pl=prev;
            prev=temp;
            temp=temp->next;
        }
        int t=l-n;
        if(n==l)
        {
            ListNode *curr=head;
            head=head->next;
            delete curr;
            return head;
        }
        if(n==1)//lastnode
        {
            pl->next=NULL;
            delete prev;
            return head;
        }
        temp=head;
        int i=1;
        while(i<t)
        {
            temp=temp->next;
            i++;
        }
        ListNode *nextnode=temp->next;
        temp->next=nextnode->next;
        delete nextnode;
        return head;


    }
};
