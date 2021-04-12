#pragma once
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Constants.h"

using namespace std;

namespace itis {
  struct SuffixTree{
   public:

      int root, last_added, pos, needSL, remainder, active_node, active_e, active_len;
      node tree[2*MAXN];
      char text[MAXN];

      int new_node(int start, int end = oo) {
        node nd;
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

      void add_SL(int node) {
        if (needSL > 0) tree[needSL].slink = node;
        needSL = node;
      }

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

      void st_extend(char c) {
        text[++pos] = c;
        needSL = 0;
        remainder++;
        while(remainder > 0) {
          if (active_len == 0) active_e = pos;
          if (tree[active_node].next[active_edge()] == 0) {
            int leaf = new_node(pos);
            tree[active_node].next[active_edge()] = leaf;
            add_SL(active_node);
          } else {
            int nxt = tree[active_node].next[active_edge()];
            if (walk_down(nxt)) continue;
            if (text[tree[nxt].start + active_len] == c) {
              active_len++;
              add_SL(active_node);
              break;
            }
            int split = new_node(tree[nxt].start, tree[nxt].start + active_len);
            tree[active_node].next[active_edge()] = split;
            int leaf = new_node(pos);
            tree[split].next[c] = leaf;
            tree[nxt].start += active_len;
            tree[split].next[text[tree[nxt].start]] = nxt;
            add_SL(split); //rule 2
          }
          remainder--;
          if (active_node == root && active_len > 0) {
            active_len--;
            active_e = pos - remainder + 1;
          } else
            active_node = tree[active_node].slink > 0 ? tree[active_node].slink : root;
        }
      }
  }; // SuffixTree
}  // namespace itis