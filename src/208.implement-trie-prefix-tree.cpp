/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#pragma once

#include <iostream>
#include <queue>

class Trie {
public:
  Trie() : root(new Node()) {}
  void insert(const std::string &str) {
    Node *cur = root;
    auto p = str.begin();
    while (p != str.end()) {
      if (cur->children[*p - 'a'] == nullptr) {
        auto node = new Node();
        cur->children[*p - 'a'] = node;
        cur = node;
      } else
        cur = cur->children[*p - 'a'];
      p++;
    }
    cur->trmt = true;
  }

  bool search(const std::string &str) {
    Node *cur = root;
    for (auto it = str.begin(); it != str.end(); it++) {
      cur = cur->children[*it - 'a'];
      if (cur == nullptr) {
        return false;
      }
    }
    if (cur->trmt == true)
      return true;
    else {
      return false;
    }
  }

  bool startsWith(const std::string &prefix) {
    Node *cur = root;
    for (auto it = prefix.begin(); it != prefix.end(); it++) {
      cur = cur->children[*it - 'a'];
      if (cur == nullptr) {
        return false;
      }
    }
    return true;
  }

  ~Trie() {
#define N 26
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      for (int i = 0; i < N; i++) {
        if(node->children[i] != nullptr) q.push(node->children[i]);
      }
      delete node;
    }
#undef N
  }

private:
  struct Node {
#define N 26
    Node *children[N];
    bool trmt;
    Node() {
      for (int i = 0; i < N; i++) {
        children[i] = nullptr;
      }
      trmt = false;
    }
#undef N
  };
  Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

