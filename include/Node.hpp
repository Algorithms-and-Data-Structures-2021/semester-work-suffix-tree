#pragma once
#include "SuffixTree.hpp"
#include "Constants.hpp"
#include <algorithm>


namespace itis {
  struct Node {
    int start, end, slink;
    int next[ALPHABET_SIZE]; // if there is an edge from node starting with certain ASCII letter

    int edge_length(int pos) {
      return std::min(end, pos + 1) - start;
    }
  };
}
