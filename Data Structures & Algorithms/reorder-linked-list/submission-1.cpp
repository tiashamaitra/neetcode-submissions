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

        // Count number of nodes
        while(temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        // Find end of first half
        int i = 1;
        temp = head;

        while(i < (n / 2))
        {
            temp = temp->next;
            i++;
        }

        // Separate the two halves
        ListNode *second = temp->next;
        temp->next = NULL;

        // Reverse second half
        ListNode *sechalf = reverse(second);

        // Merge the two halves
        ListNode *firsthalf = head;
        ListNode *last = NULL;

        while(firsthalf != NULL && sechalf != NULL)
        {
            ListNode *nextnode1 = firsthalf->next;
            ListNode *nextnode2 = sechalf->next;

            firsthalf->next = sechalf;
            sechalf->next = nextnode1;

            // Keep track of the last node
            last = sechalf;

            firsthalf = nextnode1;
            sechalf = nextnode2;
        }

        // If one node is left in the second half
        if(sechalf != NULL)
        {
            last->next = sechalf;
        }
    }
};