class Solution {
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr != NULL)
        {
            ListNode *nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }

        return prev;
    }

    void reorderList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return;

        ListNode *temp = head;
        int n = 0;

        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        int i = 1;
        temp = head;

        while(i < (n/2))
        {
            temp = temp->next;
            i++;
        }

        ListNode *second = temp->next;
        temp->next = NULL;

        ListNode *sechalf = reverse(second);
        ListNode *firsthalf = head;
        ListNode *t=NULL;
        while(firsthalf != NULL && sechalf != NULL)
        {
            ListNode *nextnode1 = firsthalf->next;
            ListNode *nextnode2 = sechalf->next;

            firsthalf->next = sechalf;
            sechalf->next = nextnode1;
            t=sechalf;
            firsthalf = nextnode1;
            sechalf = nextnode2;
        }

        // Remaining middle node in an odd-sized list
        if(sechalf != NULL)
        {
            t->next = sechalf;
        }
    }
};