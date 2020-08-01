/**
 * NSC. No Semicolon C.
 * Converts files without semicolons to .c or .cpp files.
 *
 * nsc - bin file.
 *
 * Example:
 * $ nsc main.nsc
 *
 * Outputs main.cpp
 *
 * @author motobep: <motobep@yandex.ru>
 * @date  2020.08.01
 * @version: 0.1
 */

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "nsc.h"


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
namespace fs = std::filesystem;


int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    cout << "Must be at least 1 arg.\n";
    return 0;
  }

  const str OUTPUT_EXTENSION = ".cpp"; // Put ".c" for c-files.
  const str OUTPUT_DIR = "./"; // Specify your output directory.

  for (int i = 1; i < argc; i++)
  {
    const str INPUT(argv[i]); // input filename
    const str OUTPUT = OUTPUT_DIR + nsc::get_output(INPUT) + OUTPUT_EXTENSION;

    if (!fs::exists(INPUT))
    {
      cout << INPUT << " doesn't exist.\n";
      return 0;
    }

    fs::create_directory(OUTPUT_DIR);

    str line;

    ifstream fin(INPUT);
    ofstream fout(OUTPUT);

    while (getline(fin, line))
    {
      nsc::rtrim(line);
      fout << line;
      const char last_char = line.back();

      // Handle preprocessor's dirictives ( !(ltrim_copy(line)[0] == '#') ).
      if (last_char && !(nsc::ltrim_copy(line)[0] == '#'))
      {
        switch (last_char)
        {
        case ';':
        case '{':
        case '}':
        case ',':
        case ':':
        case '<':
        case '>':
        case '\\':
          break;
        case ')':
          if (!nsc::is_next('{', fin))
          {
            fout << ';';
          }
          break;
        default:
          fout << ';';
        }
      }
      fout << endl;
    }
  }

  return 0;
}
