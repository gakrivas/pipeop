#include "pipeop.hpp"

#include <functional>
#include <ranges>

namespace pipeop {

std::vector<int> squares_of_evens(const std::vector<int>& input) {
    return input
         | std::views::filter([](int n) { return n % 2 == 0; })
         | std::views::transform([](int n) { return n * n; })
         | std::ranges::to<std::vector>();
}

std::map<std::string, std::size_t> word_lengths(const std::vector<std::string>& words) {
    return words
         | std::views::transform([](const std::string& w) { return std::pair{w, w.size()}; })
         | std::ranges::to<std::map>();
}

std::set<int> to_unique_sorted(const std::vector<int>& input) {
    return input | std::ranges::to<std::set>();
}



} // namespace pipeop
