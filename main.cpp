#include <iostream>
#include "SuffixTree.hpp"
#include <string>

using namespace std;
using namespace itis;

int main() {
  SuffixTree* tree = new SuffixTree;
  tree->st_init();
  string texts;

  cin >> texts;
  for (auto i : texts) {
    tree->st_extend(i);
    cout << tree->active_node;
  }

  delete tree;
  return 0;
}