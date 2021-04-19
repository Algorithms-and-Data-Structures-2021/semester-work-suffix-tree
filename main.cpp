#include <iostream>
#include "SuffixTree.hpp"

using namespace std;
using namespace itis;

int main() {
  SuffixTree* tree = new SuffixTree;
  tree->st_init();
  string texts = "procedure";

  // cin >> texts;
  for (auto i : texts) {
    tree->st_extend(i);
  }


  tree->checkForSubString("proce");
  delete tree;
  return 0;
}