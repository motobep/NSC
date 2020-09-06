/**
 * NSC functions.
 *
 * @author motobep: <motobep@yandex.ru>
 */

#include <ios>
#include "nsc.h"

namespace nsc
{

// Is next charcacter "ch" or not. NOTICE: it ignores spaces
bool is_next(const char &ch, std::ifstream &fin)
{
  str line = peek_line(fin);
  ltrim(line);
  return line[0] == ch;
}

// It's like fin.peek() but for line.
str peek_line(std::ifstream &fin)
{
  str line;

  // Get current position
  int current = fin.tellg();
  getline(fin, line);

  // Return to previous position
  fin.seekg(current, std::ios_base::beg);

  return line;
}

str get_last_word(const str &s)
{
  auto index = s.find_last_of(' ');
  return s.substr(++index);
}

} // namespace nsc
