#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol642;
using namespace std;

/*takeaways
  - construct a trie tree to record all sentences
    in the form of prefixes
    - insert a new sentence to a trie tree
    - find all sentences that have the same given
      prefix
  - for the implementation of the auto complete
    system it will be straight forward once you
    have the trie in place
*/

AutocompleteSystem::AutocompleteSystem(vector<string> &ss, vector<int> &ts)
{
  for (auto i = 0; i < ss.size(); i++)
    trie.insert(ss[i], ts[i]);
}
vector<string> AutocompleteSystem::input(char c)
{
  if (c == '#')
  {
    trie.insert(sentence, 1);
    sentence = "";
    return {};
  }

  sentence += c;

  auto ss = trie.startsWith(sentence);

  /* sort the sentences by frequency in descending order and
     the content of sentence in ASCII ascending order
   */

  sort(ss.begin(), ss.end(), [](const pair<int, string> &s1, const pair<int, string> &s2)
       {
         /* frequncey in descending order */
         if (s1.first != s2.first)
           return s1.first > s2.first;
         /* if same frequency then sort the content in ASCII ascending order */  
         return s1.second < s2.second; });

  auto result = vector<string>();

  for (auto i = 0; i < min(3, (int)ss.size()); i++)
    result.push_back(ss[i].second);

  return result;
}

void Trie::findss(Node *cur, const string &prefix, vector<pair<int, string>> &result)
{
  /* find a complete sentence, but don't stop here as
     multiple sentences can share the same prefix
  */
  if (cur->freq)
    result.push_back({cur->freq, prefix});

  /* exhaust all paths from this point onward */
  for (auto &[c, next] : cur->next)
    findss(next, prefix + c, result);
}

void Trie::insert(const string &sentence, int f)
{
  auto visit = root;

  /* construct the prefix path for the word */
  for (auto c : sentence)
  {
    /* construct a new node if this path has not been recorded before */
    if (!visit->next.count(c))
      visit->next[c] = new Node();
    visit = visit->next[c];
  }
  /* record the frequency */
  visit->freq = f;
}

/* find words that start with this prefix
 */
vector<pair<int, string>> Trie::startsWith(const string &prefix)
{
  auto visit = root;
  for (auto c : prefix)
  {
    /* we have not recorded this prefix yet in the system
     */
    if (!visit->next.count(c))
      return {};
    visit = visit->next[c];
  }

  auto result = vector<pair<int, string>>();

  findss(visit, prefix, result);

  return result;
}
