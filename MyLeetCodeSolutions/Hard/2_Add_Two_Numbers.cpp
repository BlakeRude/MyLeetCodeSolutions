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

//Initial solution, had a memory problem at r1 += (*it * pow(10, i)); with i>32
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Init helper vector and list results(for turning list into int)
        vector<int> helper;
        unsigned long long int r1=0, r2=0;

        // Traverse l1, adding *->val onto helper vector
        ListNode* temp = new ListNode;
        temp = l1;
        helper.push_back(temp->val);
        while(temp->next != nullptr)
        {
            temp = temp->next;
            helper.push_back(temp->val);
        }
        // Iterate helper vector converting list nums into base 10
        int i=0;
        for(vector<int>::iterator it = helper.begin(); it != helper.end(); ++it)
        {
            r1 += (*it * pow(10, i));
            i++;
        }
        
        // clear helper, Traverse l2, adding *->val onto helper vector
        helper.clear();
        temp = l2;
        helper.push_back(temp->val);
        while(temp->next != nullptr)
        {
            temp = temp->next;
            helper.push_back(temp->val);
        }
        // Iterate helper vector converting list nums into base 10
        i=0;
        for(vector<int>::iterator it = helper.begin(); it != helper.end(); ++it)
        {
            r2 += (*it * pow(10, i));
            i++;
        }
        // Take result and convert to string
        string r = to_string(r1 + r2);
        int l = r.length() - 1;
        
        // Create solution vector adding on each digit of out result per node
        ListNode* solution = new ListNode(static_cast<int>(r[l] - '0'));
        ListNode* s = solution; 
        for(int i = l-1; i>-1; i--)
        {
            s->next = new ListNode(static_cast<int>(r[i] - '0'));
            s = s->next;
        }
        return solution;
    }
};

//A better solution which passes
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if (l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return head->next;
    }
};