class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        Node *temp = head;
        int arr[];
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            arr.add(temp->val);
            temp = temp->next->next;
        }
        temp = head->next;
    }
};