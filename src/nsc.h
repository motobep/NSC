/**
 * NSC header file.
 *
 * @author motobep: <motobep@yandex.ru>
 */

#ifndef NSC
#define NSC

#include <fstream>
#include <string>
#include "trim.h"


namespace nsc
{
using std::string;

inline bool is_comment_line(const string &s)
{
  const string s_ltrimmed = ltrim_copy(s);
  return s_ltrimmed[0] == '/' && s_ltrimmed[1] == '/';
}

inline bool is_preprocessor_dirictive(string &line)
{
  return ltrim_copy(line)[0] == '#';
}

inline string get_output(const string &input)
{
  string rawname = input;
  size_t lastindex = input.find_last_of(".");
  if (lastindex != string::npos)
  {
    rawname = input.substr(0, lastindex);
  }
  return rawname;
}

// Is next charcacter "ch" or not. NOTICE: it ignores spaces
bool is_next(const char &ch, std::ifstream &fin);

// It's like fin.peek() but for line.
string peek_line(std::ifstream &fin);

string get_last_word(const string &s);

} // namespace nsc

#endif
