/**
 * NSC trim functions.
 * The functions delete spaces.
 *
 * @author motobep: <motobep@yandex.ru>
 */

#ifndef NSC_TRIM
#define NSC_TRIM

#include <string>
#include <algorithm>


namespace nsc
{
using std::string;

// trim from start (by reference)
static inline void ltrim(string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (by reference)
static inline void rtrim(string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
          }).base(),
          s.end());
}

// trim from both ends (by reference)
static inline void trim(string &s)
{
  ltrim(s);
  rtrim(s);
}

// trim from start (copying)
static inline string ltrim_copy(string s)
{
  ltrim(s);
  return s;
}

// trim from end (copying)
static inline string rtrim_copy(string s)
{
  rtrim(s);
  return s;
}

// trim from both ends (copying)
static inline string trim_copy(string s)
{
  trim(s);
  return s;
}

}

#endif
