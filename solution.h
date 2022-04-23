
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
namespace sol642
{
  class Trie
  {
  private:
    Node *root = new Node;
    void findss(Node *cur, const string &prefix, vector<pair<int, string>> &result);

  public:
    void insert(const string &sentence, int f);
    vector<pair<int, string>> startsWith(const string &prefix);
  };

  class AutocompleteSystem
  {
  private:
    Trie trie;
    string sentence;

  public:
    AutocompleteSystem(vector<string> &ss, vector<int> &ts);
    vector<string> input(char c);
  };
}
#endif