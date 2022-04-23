#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
#include <unordered_map>
using namespace std;

namespace sol642
{
    struct Node
    {
        unordered_map<char, Node *> next;
        int freq = 0;
    };
}
#endif