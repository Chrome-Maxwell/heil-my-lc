/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
// @lc code=start
#include <bits/stdc++.h>
using namespace std;
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else
        {
            if (l1->val < l2->val)
            {
                ListNode *l1_rest = l1->next;
                l1->next = mergeTwoLists(l1_rest, l2);
                return l1;
            }
            else
            {
                ListNode *l2_rest = l2->next;
                l2->next = mergeTwoLists(l2_rest, l1);
                return l2;
            }
        }
    }
};
// @lc code=end
