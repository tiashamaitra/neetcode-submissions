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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1;
        ListNode *t2=l2;
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *originaldummy=dummy;
        while(t1!=NULL && t2!=NULL)
        {
            int sum=0;
            if(carry!=0)
            {
                sum=sum+carry;
            }
            sum+=t1->val+t2->val;
            
            if(sum>=10)
            {
                carry=sum/10;
            }
            else if(sum<10)
            {
                carry=0;
            }
            int rem=sum%10;
            ListNode *d=new ListNode(rem);
            dummy->next=d;
            dummy=d;
            t1=t1->next;
            t2=t2->next;

        }

        while(t1!=NULL)
        {
            int sum=0;
            if(carry!=0)
            {
                sum=sum+carry;
            }
            sum+=t1->val;
            if(sum>=10)
            {

                
                carry=sum/10;
            }
            else if(sum<10)
            {
                carry=0;
            }
            int rem=sum%10;
            ListNode *d=new ListNode(rem);
            dummy->next=d;
            dummy=d;
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            int sum=0;
            if(carry!=0)
            {
                sum=sum+carry;
            }
            sum+=t2->val;
            if(sum>=10)
            {
                
                
                carry=sum/10;
            }
            else if(sum<10)
            {
                carry=0;
            }
            int rem=sum%10;
            ListNode *d=new ListNode(rem);
            dummy->next=d;
            dummy=d;
            t2=t2->next;
        }
        if(carry!=0)
        {
            
            ListNode *d=new ListNode(carry);
            dummy->next=d;
        }
        return originaldummy->next;
    }
};
