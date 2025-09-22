#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  std::set<string> results;
  string temp;

  while (rawWords.length() >= 2) {
    int i = 0;
    bool found = false;
    for (; i < rawWords.length(); i++) {
      if (ispunct(rawWords[i]) || isspace(rawWords[i])) {
        temp = rawWords.substr(0, i);
        if (temp.length() >= 2) {
          results.insert(convToLower(temp));
        }
        rawWords.erase(0, i + 1);
        found = true;
        break;
      }
    }

    if (!found) {
      if (rawWords.length() >= 2) {
        results.insert(convToLower(rawWords));
      }
      break;
    }
  }

  return results;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
