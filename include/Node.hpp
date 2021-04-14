#pragma once
#include "SuffixTree.hpp"
#include "Constants.h"

using namespace std;

namespace itis {
  struct Node {
    int start, end, slink;
    int next[ALPHABET_SIZE];

    int edge_length(int pos) {
      return fmin(end, pos + 1) - start;
    }
  };
}
