/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head, *p2 = head;
        while(p2->next != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
            if(p2->next != nullptr) {
                p2 = p2->next;
            }
            else break;
        }
        return p1;
    }
};
// @lc code=end

