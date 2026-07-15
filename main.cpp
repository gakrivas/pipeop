#include <format>
#include <print>
#include <ranges>
#include <string>
#include <vector>

#include "pipeop.hpp"

namespace {

template <std::ranges::input_range Range, typename Fn>
std::string join(const Range& range, Fn format_one) {
    return range
         | std::views::transform(format_one)
         | std::views::join_with(std::string{", "})
         | std::ranges::to<std::string>();
}

} // namespace

int main() {
    const std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::println("Squares of evens: {}",
                 join(pipeop::squares_of_evens(numbers), [](int n) { return std::format("{}", n); }));

    const std::vector<std::string> words{"cpp", "ranges", "to"};
    std::println("Word lengths: {}",
                 join(pipeop::word_lengths(words),
                      [](const auto& kv) { return std::format("{} -> {}", kv.first, kv.second); }));

    std::println("Unique sorted: {}",
                 join(pipeop::to_unique_sorted({5, 3, 5, 1, 4, 3, 2}), [](int n) { return std::format("{}", n); }));


    return 0;
}
