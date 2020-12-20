/**
 * NSC functions.
 *
 * @author motobep: <motobep@yandex.ru>
 */

#include <ios>
#include "nsc.h"

namespace nsc
{
using std::string;

// Is next charcacter "ch" or not. NOTICE: it ignores spaces
bool is_next(const char &ch, std::ifstream &fin)
{
  string line = peek_line(fin);
  ltrim(line);
  return line[0] == ch;
}

// It's like fin.peek() but for line.
string peek_line(std::ifstream &fin)
{
  string line;

  // Get current position
  int current = fin.tellg();
  getline(fin, line);

  // Return to previous position
  fin.seekg(current, std::ios_base::beg);

  return line;
}

string get_last_word(const string &s)
{
  auto index = s.find_last_of(' ');
  return s.substr(++index);
}

} // namespace nsc
