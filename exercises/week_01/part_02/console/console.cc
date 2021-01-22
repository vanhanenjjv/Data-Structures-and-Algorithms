#include "console.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

static inline void ltrim(std::string &str) {
  str.erase(
    str.begin(), 
    std::find_if(
      str.begin(), 
      str.end(), 
      [](unsigned char ch) { return !std::isspace(ch); }
    )
  );
}

static inline void rtrim(std::string &str) {
  str.erase(
    std::find_if(
      str.rbegin(), 
      str.rend(), 
      [](unsigned char ch) { return !std::isspace(ch); }
    ).base(),
    str.end()
  );
}

static inline void trim(std::string &str) {
  ltrim(str);
  rtrim(str);
}

bool console::Prompt(const char *description) {
  std::string input;

  while (true) {
    if (!input.empty()) std::cout << "Invalid input.\n";

    std::cout << description << "? (y/n): ";
    std::cin >> input;

    trim(input);

    if (input == "n" || input == "N") return false;
    if (input == "y" || input == "Y") return true;
  }
}
