#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol642;

/*
AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
Operation: input('i')
Output: ["i love you", "island","i love leetcode"]
Operation: input(' ')
Output: ["i love you","i love leetcode"]
Operation: input('a')
Output: []
Operation: input('#')
Output: []
*/

void test1()
{
  auto ss = vector<string>{"i love you", "island", "ironman", "i love leetcode"};
  auto ts = vector<int>{5, 3, 2, 2};
  auto sys = AutocompleteSystem(ss, ts);

  cout << "Expect to see [\"i love you\", \" island \",\"i love leetcode \"] " << endl;
  cout << Util::toString(sys.input('i')) << endl;
  cout << "Expect to see [\"i love you\",\"i love leetcode \"] " << endl;
  cout << Util::toString(sys.input(' ')) << endl;
  cout << "Expect to see [] " << endl;
  cout << Util::toString(sys.input('a')) << endl;
  cout << "Expect to see [] " << endl;
  cout << Util::toString(sys.input('#')) << endl;
}

main()
{
  test1();

  return 0;
}