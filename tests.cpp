// #include <boost/shared_ptr.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <src/solution.hpp>

namespace codility
{

using namespace std;
using namespace codility;

TEST(Codility, lesson1)
{
  EXPECT_EQ(lesson1::solution(9), 2); // 1001
  EXPECT_EQ(lesson1::solution(529), 4); // 1000010001
  EXPECT_EQ(lesson1::solution(20), 1); // 10100
  EXPECT_EQ(lesson1::solution(15), 0); // 1111
  EXPECT_EQ(lesson1::solution(32), 0); // 100000
}

TEST(Codility, lesson2)
{
  std::vector<int> input = {3, 8, 9, 7, 6};
  EXPECT_THAT(lesson2::solution(input, 3),
      testing::ElementsAreArray(std::vector<int>{9, 7, 6, 3, 8}));

  std::vector<int> input2 = {0, 0, 0};
  EXPECT_THAT(lesson2::solution(input2, 1),
      testing::ElementsAreArray(std::vector<int>{0, 0, 0}));

  std::vector<int> input3 = {1, 2, 3, 4};
  EXPECT_THAT(lesson2::solution(input3, 4),
      testing::ElementsAreArray(std::vector<int>{1, 2, 3, 4}));
}

TEST(Codility, lesson13)
{
  std::string S = "CAGCCT";
  std::vector<int> P = {2 ,5 ,0};
  std::vector<int> Q = {4, 5, 6};

  EXPECT_THAT(lesson13::solution(S, P, Q), testing::ElementsAre(2, 4, 1));

  std::string S2 = "AC";
  std::vector<int> P2 = {0, 0, 1};
  std::vector<int> Q2 = {0, 1, 1};

  EXPECT_THAT(lesson13::solution(S2, P2, Q2), testing::ElementsAre(1, 1, 2));

  std::string S3 = "GT";
  std::vector<int> P3 = {0, 0, 1};
  std::vector<int> Q3 = {0, 1, 1};

  EXPECT_THAT(lesson13::solution(S3, P3, Q3), testing::ElementsAre(3, 3, 4));
}

TEST(Codility, lesson14)
{
  std::vector<int> input = {4, 2, 2, 5, 1, 5, 8};
  EXPECT_EQ(lesson14::solution(input), 1);

  std::vector<int> input2 = {4, 5, 6, 10, 2, 2, 5, 1, 5, 8};
  EXPECT_EQ(lesson14::solution(input2), 4);

  std::vector<int> input3 = {-1, 1, 1, 0, -1, 1, -1, 0, 1, 1};
  EXPECT_EQ(lesson14::solution(input3), 3);

  std::vector<int> input4 = {5, 6, 3, 4, 9};
  EXPECT_EQ(lesson14::solution(input4), 2);
}

TEST(Codility, brackets)
{
  std::string input = "(()(())())";
  EXPECT_EQ(brackets::solution(input), 1);

  input = "";
  EXPECT_EQ(brackets::solution(input), 1);

  input = "())";
  EXPECT_EQ(brackets::solution(input), 0);

  input = "(";
  EXPECT_EQ(brackets::solution(input), 0);
  
  input = ")";
  EXPECT_EQ(brackets::solution(input), 0);

  ///////////////////////////

  std::string input2 = "{[()()]}";
  EXPECT_EQ(brackets::solution(input2), 1);

  input2 = "([)()]";
  EXPECT_EQ(brackets::solution(input2), 0);
}

} // codility
