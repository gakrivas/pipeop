#include "pipeop.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::ElementsAre;

TEST(SquaresOfEvens, FiltersThenSquares) {
    const std::vector<int> input{1, 2, 3, 4, 5, 6};
    EXPECT_THAT(pipeop::squares_of_evens(input), ElementsAre(4, 16, 36));
}

TEST(SquaresOfEvens, EmptyInputYieldsEmptyOutput) {
    EXPECT_TRUE(pipeop::squares_of_evens({}).empty());
}

TEST(WordLengths, MapsWordToLength) {
    const std::vector<std::string> words{"cpp", "ranges", "to"};
    const auto result = pipeop::word_lengths(words);
    EXPECT_EQ(result.at("cpp"), 3u);
    EXPECT_EQ(result.at("ranges"), 6u);
    EXPECT_EQ(result.at("to"), 2u);
    EXPECT_EQ(result.size(), 3u);
}

TEST(ToUniqueSorted, DedupsAndSorts) {
    const std::vector<int> input{5, 3, 5, 1, 4, 3, 2};
    const auto result = pipeop::to_unique_sorted(input);
    EXPECT_THAT(result, ElementsAre(1, 2, 3, 4, 5));
}
