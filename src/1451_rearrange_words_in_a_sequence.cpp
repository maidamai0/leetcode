#include "common/common.hpp"

using std::string;
using std::vector;

class Solution {
public:
  string arrangeWords(string text) {
    text[0] = std::tolower(text[0]);
    std::map<size_t, std::vector<std::string>> strs;
    std::stringstream ss(text);

    std::string word;
    while (ss >> word) {
      strs[word.size()].push_back(word);
    }

    strs.begin()->second[0][0] = std::toupper(strs.begin()->second[0][0]);

    std::string ret;
    for (const auto &kv : strs) {
      for (const auto &word : kv.second) {
        ret += word;
        ret += " ";
      }
    }

    ret.pop_back(); // pop last " "

    return ret;
  }
};

TEST_CASE("rearrange_words") {
  Solution sln;
  CHECK(sln.arrangeWords("Leetcode is cool") == "Is cool leetcode");
  CHECK(sln.arrangeWords("Aaaa bb cc") == "Bb cc aaaa");
  CHECK(sln.arrangeWords("Keep calm and code on") == "On and keep calm code");
  CHECK(sln.arrangeWords("To be or not to be") == "To be or to be not");
  CHECK(sln.arrangeWords(
            "Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi "
            "qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr "
            "xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry") ==
        "Kry hkbwx ubogo xqpqd jlhvvd qcuucx xmwohi qvzegb qsvqskq llwzeug "
        "ipwbapd cqwfypww dyphntfz tuqppyipb dkvhhgecd wfwnphmxoa sbdfmnyeim "
        "hrsaebveez aszqnvruhr mlghuuwvec xpefyglstj");
}