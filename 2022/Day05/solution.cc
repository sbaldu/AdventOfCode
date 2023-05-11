#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void create_stacks(std::vector<std::vector<char>>& stacks, std::string const& path) {
  std::ifstream file(path);
  std::string file_row;
  char letter;
  std::string temp;

  int number_of_stacks{};
  while (true) {
    // Write the row from the file inside a string
    getline(file, file_row);
    if (number_of_stacks == 0) {
      number_of_stacks = (file_row.size() + 1) / 4;
      stacks.resize(number_of_stacks);
    }
    if (file_row == "") {
      break;
    }

    for (int i{}, j{}; i < number_of_stacks; ++i, j += 4) {
      std::string crate = file_row.substr(j, 4);
      // Clean the crate string
      crate.erase(std::remove(crate.begin(), crate.end(), '['), crate.end());
      crate.erase(std::remove(crate.begin(), crate.end(), ']'), crate.end());
      crate.erase(std::remove(crate.begin(), crate.end(), ' '), crate.end());

      if (crate != "") {
        stacks[i].push_back(crate[0]);
      }
    }
  }
  for (auto& stack : stacks) {
    stack.pop_back();
  }
}

template <typename T>
void flip_vector(std::vector<T>& vec) {
  std::size_t size{vec.size()};
  std::vector<T> temp(size);

  for (int i{}; i < size; ++i) {
    temp[i] = vec[size - 1 - i];
  }

  vec = temp;
}

void move(std::vector<std::vector<char>>& stacks, int n_crates, int starting_crate, int ending_crate) {
  for (int i{}; i < n_crates; ++i) {
    stacks[ending_crate - 1].push_back(*(stacks[starting_crate - 1].end() - 1));
    stacks[starting_crate - 1].pop_back();
  }
}

void new_move(std::vector<std::vector<char>>& stacks, int n_crates, int starting_crate, int ending_crate) {
  for (int i{1}; i <= n_crates; ++i) {
    stacks[ending_crate - 1].push_back(*(stacks[starting_crate - 1].end() - 1 - n_crates + i));
  }
  for (int i{}; i < n_crates; ++i) {
    stacks[starting_crate - 1].pop_back();
  }
}

void find_final_stacks(std::vector<std::vector<char>>& stacks, std::string const& file_path) {
  create_stacks(stacks, file_path);
  for (auto& stack : stacks) {
    flip_vector(stack);
  }

  std::ifstream file(file_path);
  std::string file_row;
  std::string word;
  std::string crate;
  std::string start;
  std::string end;
  while (getline(file, file_row)) {
    std::stringstream row_stream(file_row);
    getline(row_stream, word, ' ');

    if (word != "move") {
      continue;
    }

    getline(row_stream, crate, ' ');
    getline(row_stream, word, ' ');
    getline(row_stream, start, ' ');
    getline(row_stream, word, ' ');
    getline(row_stream, end);

    move(stacks, std::stoi(crate), std::stoi(start), std::stoi(end));
    std::cout << "------------------------------" << std::endl;
    for (auto const& stack : stacks) {
      std::cout << *(stack.end() - 1) << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
  }
}

void find_new_final_stacks(std::vector<std::vector<char>>& stacks, std::string const& file_path) {
  create_stacks(stacks, file_path);
  for (auto& stack : stacks) {
    flip_vector(stack);
  }

  std::ifstream file(file_path);
  std::string file_row;
  std::string word;
  std::string crate;
  std::string start;
  std::string end;
  while (getline(file, file_row)) {
    std::stringstream row_stream(file_row);
    getline(row_stream, word, ' ');

    if (word != "move") {
      continue;
    }

    getline(row_stream, crate, ' ');
    getline(row_stream, word, ' ');
    getline(row_stream, start, ' ');
    getline(row_stream, word, ' ');
    getline(row_stream, end);

    new_move(stacks, std::stoi(crate), std::stoi(start), std::stoi(end));
    std::cout << "------------------------------" << std::endl;
    for (auto const& stack : stacks) {
      std::cout << *(stack.end() - 1) << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
  }
}

int main() {
  std::vector<std::vector<char>> stacks;
  std::vector<std::vector<char>> new_stacks;
  const std::string file_path{"./input.txt"};

  find_final_stacks(stacks, file_path);
  find_new_final_stacks(new_stacks, file_path);
}
