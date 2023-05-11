#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool found_marker(std::string const& str, int marker_size) {
  if (str.size() < marker_size) {
    return false;
  }

  std::vector<char> non_duplicate_letters;
  std::vector<char> letters;
  for (int i{}; i < str.size(); ++i) {
    letters.push_back(str[i]);
    if (std::find(non_duplicate_letters.begin(), non_duplicate_letters.end(), str[i]) == non_duplicate_letters.end()) {
      non_duplicate_letters.push_back(str[i]);
    }
  }

  return letters == non_duplicate_letters;
}

int main() {
  const std::string path_to_input{"./input.txt"};
  std::ifstream ifile(path_to_input);
  std::string sequence;
  std::string longer_sequence;
  bool found_first;

  int counter{};
  char letter;
  while (true) {
    ifile >> letter;
    sequence += letter;
    longer_sequence += letter;
    ++counter;

    if (ifile.eof()) {
      break;
    }
    if (sequence.size() > 4) {
      sequence.erase(sequence.begin());
    }
    if (longer_sequence.size() > 14) {
      longer_sequence.erase(longer_sequence.begin());
    }
    if (found_marker(sequence, 4) && !found_first) {
      std::cout << "The first result is: " << counter << '\n';
      found_first = true;
    }
    if (found_marker(longer_sequence, 14)) {
      std::cout << "The second result is: " << counter << '\n';
      break;
    }
  }
}
