/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root != NULL)
        {
            root->next = NULL;
            q.push(root);
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    Node *n = q.front();
                    q.pop();
                    n->next = i == size - 1 ? NULL : q.front();
                    if (n->left != NULL)
                        q.push(n->left);
                    if (n->right != NULL)
                        q.push(n->right);
                }
            }
        }

        return root;
    }
};
// @lc code=end
