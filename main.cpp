#include <iostream>
#include "SuffixTree.hpp"

using namespace std;
using namespace itis;

int main() {
  auto tree = new SuffixTree;
  tree->st_init();

  /* ========= Поиск подстроки в коде ДНК ========= */

  string DNA = "TAGGTT";

  for (auto i : DNA) {
    tree->st_extend(i);
  }

  tree->checkForSubString("GTT");

  delete tree;

  /* ============================================== */

  /* ========= Поиск подстроки в длинном тексте ========= */

  string text = "In this world, there are things you can only do alone, and things you can only do with somebody else."
                " It's important to combine the two in just the right amount.";

  auto tree1 = new SuffixTree;
  tree1->st_init();
  for (auto i : text) {
    tree1->st_extend(i);
  }

  tree1->checkForSubString("just the right amount");

  delete tree1;

  /* ==================================================== */

  return 0;
}