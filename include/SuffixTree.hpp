#pragma once
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Constants.h"

using namespace std;

namespace itis {
  struct SuffixTree{
   public:
      int root, last_added,
          pos, // position at text
          needSL, // current node that needs suffix link
          remainder, // how many nodes we need to lengthen
          active_node, active_e, active_len;

      Node tree[MAXN];
      char text[MAXN];

      int new_node(int start, int end = oo) {
        Node nd;
        nd.start = start;
        nd.end = end;
        nd.slink = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
          nd.next[i] = 0;
        tree[++last_added] = nd;
        return last_added;
      }

      char active_edge() {
        return text[active_e];
      }

      // only adds SL if called on node in the same iteration of WHILE
      void add_SL(int node) {
        if (needSL > 0) tree[needSL].slink = node;
        needSL = node;
      }

      // going down on the edge to the node
      bool walk_down(int node) {
        if (active_len >= tree[node].edge_length(pos)) {
          active_e += tree[node].edge_length(pos);
          active_len -= tree[node].edge_length(pos);
          active_node = node;
          return true;
        }
        return false;
      }

      void st_init() {
        needSL = 0, last_added = 0, pos = -1,
        remainder = 0, active_node = 0, active_e = 0, active_len = 0;
        root = active_node = new_node(-1, -1);
      }

      // adding new letter to text and expand our tree
      void st_extend(char c) {
        text[++pos] = c;
        needSL = 0;
        remainder++;

        // while we have nodes to extend (to split)
        while(remainder > 0) {
          if (active_len == 0) active_e = pos;

          if (tree[active_node].next[active_edge()] == 0) { // if there is no such edge
            int leaf = new_node(pos);
            tree[active_node].next[active_edge()] = leaf;
            add_SL(active_node);
          } else {
            int nxt = tree[active_node].next[active_edge()];
            if (walk_down(nxt)) continue; // if we have edge starting with current symbol
            if (text[tree[nxt].start + active_len] == c) {
              active_len++;
              add_SL(active_node);
              break;
            }

            // if we have C somewhere in the middle of the edge we need to split it into two edges
            int split = new_node(tree[nxt].start, tree[nxt].start + active_len);
            tree[active_node].next[active_edge()] = split;
            int leaf = new_node(pos);
            tree[split].next[c] = leaf;
            tree[nxt].start += active_len;
            tree[split].next[text[tree[nxt].start]] = nxt;
            add_SL(split);
          }
          // it's all just a rules from here. trust me.
          remainder--;
          if (active_node == root && active_len > 0) {
            active_len--;
            active_e = pos - remainder + 1;
          } else
            active_node = tree[active_node].slink > 0 ? tree[active_node].slink : root;
        }
      }

    // ===== SEARCHING FOR SUBSTRING FUNCTIONS ===== //

    int traverseEdge(string str, int idx, int start, int end)
    {
      int k = 0;
      for(k=start; k<end && str[idx] != '\0'; k++, idx++)
      {
        if(text[k] != str[idx])
          return -1;  // traverse edge and substr accordingly, if found different symbol - quit
      }
      if(str[idx] == '\0')
        return 1;  // came to the end of substr and everything matched
      return 0;  // didnt came to the end of substr, but everything matched for now, go to the next edge
    }

    int doTraversal(Node *n, string str, int idx)
    {
      if(n == nullptr)
      {
        return -1;
      }
      int res = -1;
      // If n is not root
      if(n->start != -1)
      {
        res = traverseEdge(str, idx, n->start, n->end);
        if(res != 0)
          return res;  // match (res = 1) or (res = -1)
      }
      //If n is root or we need to traverse more edges:
      //set tge right index for our substring first
      idx = idx + n->end - n->start;
      //If there is edge starting with str[idx] then traverse it
      if(n->next[str[idx]] != 0)
        return doTraversal(&tree[n->next[str[idx]]], str, idx);
      else
        return -1;  // no such edge, no match
    }

    void checkForSubString(string str)
    {
      int res = doTraversal(&tree[root], str, 0);
      if(res == 1)
        printf("Pattern <%s> is a Substring\n", str.c_str());
      else
        printf("Pattern <%s> is NOT a Substring\n", str.c_str());
    }
  }; // SuffixTree
}  // namespace itis