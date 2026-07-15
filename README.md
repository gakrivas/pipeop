 C++23 Ranges, feat. `std::ranges::to`

## 

Highlight ranges, ranges::to, and the functional approach 




1. **`squares_of_evens`** — filter to even numbers, square them, collect
   into a `std::vector<int>`.
2. **`word_lengths`** — map each word to its length, collect into a
   `std::map<std::string, std::size_t>`.
3. **`to_unique_sorted`** — collect an unsorted, duplicate-containing
   `std::vector<int>` straight into a `std::set<int>` (no explicit sort/unique
   call — let the container do it).


