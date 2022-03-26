/**
 * @file main.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief Sed is for losers
 * @date 2022-02-26
 */

#include <fstream>
#include <iostream>
#include <string>

int ReadOriginal(std::string &original, const std::string &file_name) {
  std::ifstream file(file_name);

  if (!file.is_open()) {
    std::cout << "Error : Failed to open a file\n";
    return 0;
  }
  file.seekg(0, file.end);
  const int len = file.tellg();
  if (len == -1) {
    std::cout << "Error : tellg failed\n";
    return 0;
  }
  file.seekg(0, file.beg);
  char data[len + 1];
  data[len] = '\0';
  file.read(data, len);
  if (!file.good()) {
    std::cout << "Error : The file is open, but is not a regular file\n";
    file.close();
    return 0;
  }
  original = data;
  file.close();
  return 1;
}

void ReplacePattern(std::string &original, const std::string &s1,
                    const std::string &s2) {
  size_t length = s1.length();
  size_t pos = original.find(s1);

  while (pos != std::string::npos) {
    original.erase(pos, length);
    original.insert(pos, s2);
    pos = original.find(s1);
  }
}

int WriteReplacedFile(const std::string &replaced,
                      const std::string &file_name) {
  std::ofstream file(file_name + ".replace");

  if (!file.is_open()) {
    std::cout << "Error : Failed to create a file\n";
    return 0;
  }
  file << replaced;
  file.close();
  return 1;
}

int main(int argc, char **argv) {
  std::string content;

  if (argc != 4) {
    std::cout
        << "Error : An invalid number of arguments have been passed\nUsage : "
           "replace [filename] [str1] [str2]\n";
    return EXIT_FAILURE;
  }
  std::string patterns[2] = {argv[2], argv[3]};
  if (!patterns[0].length() || !patterns[1].length()) {
    std::cout << "Error : s1 and/or s2 are empty\n";
    return EXIT_FAILURE;
  }
  if (!ReadOriginal(content, argv[1])) return EXIT_FAILURE;
  ReplacePattern(content, argv[2], argv[3]);
  if (!WriteReplacedFile(content, argv[1])) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}