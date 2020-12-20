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
 * @date  2020.08.02
 * @version: 0.1.1
 */

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "nsc.h"


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
namespace fs = std::filesystem;


int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    cout << "Must be at least 1 arg.\n";
    return 0;
  }

  const string OUTPUT_EXTENSION = ".cpp"; // Put ".c" for c-files.
  const string OUTPUT_DIR = "./"; // Specify your output directory.

  for (int i = 1; i < argc; i++)
  {
    const string INPUT(argv[i]); // input filename
    const string OUTPUT = OUTPUT_DIR + nsc::get_output(INPUT) + OUTPUT_EXTENSION;

    if (!fs::exists(INPUT))
    {
      cout << INPUT << " doesn't exist.\n";
      return 0;
    }

    fs::create_directory(OUTPUT_DIR);

    string line;

    ifstream fin(INPUT);
    ofstream fout(OUTPUT);

    while (getline(fin, line))
    {
      nsc::rtrim(line);
      fout << line;
      const string last_word = nsc::get_last_word(line);
      const char last_char = line.back();

      if (last_char && !nsc::is_preprocessor_dirictive(line) && !nsc::is_comment_line(line) && last_word != "else")
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
          if (!nsc::is_next('{', fin) && !nsc::is_next('.', fin))
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
