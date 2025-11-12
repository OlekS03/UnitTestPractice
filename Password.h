#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>

using std::string;

class Password
{
public:
  /*
  The function receives a string and counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
  */
  int count_leading_characters(string word);

  /*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
  */
  bool has_mixed_case(string);

  unsigned int unique_characters(string);
};
#endif
