/**
 * NSC trim functions.
 * The functions delete spaces.
 *
 * @author motobep: <motobep@yandex.ru>
 * @date  2020.08.01
 */

#ifndef NSC_TRIM
#define NSC_TRIM

#include <string>
#include <algorithm>

using str = std::string;

namespace nsc
{

// trim from start (by reference)
static inline void ltrim(str &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (by reference)
static inline void rtrim(str &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
          }).base(),
          s.end());
}

// trim from both ends (by reference)
static inline void trim(str &s)
{
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
static inline str ltrim_copy(str s)
{
  ltrim(s);
  return s;
}

// trim from end (copying)
static inline str rtrim_copy(str s)
{
  rtrim(s);
  return s;
}

// trim from both ends (copying)
static inline str trim_copy(str s)
{
  trim(s);
  return s;
}

}

#endif
