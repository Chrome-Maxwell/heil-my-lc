/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1_prev = nullptr, *p1 = head, *p2 = head;
        for (int i = 0; i < n - 1; i++)
        {
            p2 = p2->next;
        }
        if(p2->next == nullptr) return head->next;
        while (p2->next != nullptr)
        {
            p2 = p2->next;
            p1_prev = p1;
            p1 = p1->next;
        }
        p1_prev->next = p1->next;
        delete p1;
        return head;
    }
};
// @lc code=end
