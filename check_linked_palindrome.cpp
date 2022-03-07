// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *pre = NULL;
        Node *cur = head;
        Node *next = head->next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    Node *midd(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *slow = head;
        Node *fast = head->next;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    bool isPalindrome(Node *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return true;
        }

        Node *mid = midd(head);
        Node *a = mid->next;
        mid->next = NULL;
        Node *secondHead = reverse(a);
        while (secondHead)
        {
            if (head->data != secondHead->data)
            {
                return false;
            }
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};
