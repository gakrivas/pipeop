#pragma once

#include <cstddef>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace pipeop {

std::vector<int> squares_of_evens(const std::vector<int>& input);

std::map<std::string, std::size_t> word_lengths(const std::vector<std::string>& words);

// Task 3: materialize an unsorted, duplicate-containing range straight into a std::set.
std::set<int> to_unique_sorted(const std::vector<int>& input);

} // namespace pipeop
