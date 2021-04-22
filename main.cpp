#include <iostream>
#include "SuffixTree.hpp"

using namespace std;
using namespace itis;

int main() {
  auto tree = new SuffixTree;
  tree->st_init();
  string texts = "procedure";

  // cin >> texts;
  for (auto i : texts) {
    tree->st_extend(i);
  }


  tree->checkForSubString("dure");

  delete tree;
  return 0;
}