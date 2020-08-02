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

using str = std::string;

namespace nsc
{

inline str get_output(const str &input)
{
  str rawname = input;
  size_t lastindex = input.find_last_of(".");
  if (lastindex != str::npos)
  {
    rawname = input.substr(0, lastindex);
  }
  return rawname;
}

// Is next charcacter "ch" or not. NOTICE: it ignores spaces
bool is_next(const char &ch, std::ifstream &fin);

// It's like fin.peek() but for line.
str peek_line(std::ifstream &fin);

} // namespace nsc

#endif
