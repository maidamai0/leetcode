/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include "common/common.hpp"

// @lc code=start
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    elements_.push_back(x);
    if (min_.empty() || x <= getMin()) {
      min_.push_back(x);
    }
  }

  void pop() {
    if (elements_.back() == min_.back()) {
      min_.pop_back();
    }
    elements_.pop_back();
  }

  int top() { return elements_.back(); }

  int getMin() { return min_.back(); }

private:
  std::vector<int> elements_;
  std::vector<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// constexpr std::string_view ctor{"MinStack"};
// constexpr std::string_view push{"push"};
// constexpr std::string_view getMin{"getMin"};
// constexpr std::string_view pop{"pop"};
// constexpr std::string_view top{"top"};

enum class OperationType : char { MinStack, push, getMin, pop, top };

struct Operation {
  OperationType operation_;
  int argument_ = 0;
  int result_ = 0;

  Operation(const OperationType type) : operation_(type) {}

  auto operator()(MinStack &minstack) -> bool {
    switch (operation_) {
    case OperationType::MinStack: {
      minstack = MinStack();
      return true;
    }
    case OperationType::push: {
      minstack.push(argument_);
      return true;
    }
    case OperationType::getMin: {
      return minstack.getMin() == result_;
    }
    case OperationType::pop: {
      minstack.pop();
      return true;
    }
    case OperationType::top: {
      return minstack.top() == result_;
    }
    default: {
      return false;
    }
    }
  }
};

std::vector<Operation> parse_case(std::string &&str) {
  const auto new_line =
      std::find(str.cbegin(), str.cend(), '\n') - str.cbegin();
  std::string operation = str.substr(1, new_line - 1);
  auto args = str.substr(new_line + 1);
  args.pop_back(); // remove last ']'

  size_t cnt = 0;
  std::vector<Operation> ret;
  std::string temp;
  for (const auto c : operation) {
    if (c == '\"') {
      ++cnt;
      continue;
    }

    if (cnt & 0x01) {
      // odd,open quote
      temp.push_back(c);
    } else {
      // even, close quote
      try {
        ret.emplace_back(magic_enum::enum_cast<OperationType>(temp).value());
      } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        abort();
      }

      temp.clear();
    }
  }

  temp.clear();
  cnt = 0;
  size_t index = 0;
  bool valid = false;
  for (const auto c : args) {
    if (c == '[') {
      valid = true;
      continue;
    }

    if (c == ']') {
      if (!temp.empty()) {
        try {
          ret[index].argument_ = std::stoi(temp);
        } catch (const std::exception &e) {
          std::cerr << e.what() << '\n';
          abort();
        }

        temp.clear();
      }
      ++index;
      valid = false;
      continue;
    }

    if (valid) {
      temp.push_back(c);
    }
  }

  return ret;
}

void parse_expect_result(std::vector<Operation> &op, std::string &&result) {
  result = result.substr(std::find(result.begin(), result.end(), '[') -
                         result.begin() + 1); // remove [
  result.pop_back();                          // remove ]

  size_t index = 0;
  std::string temp;
  for (const auto c : result) {
    if (c != ',') {
      temp.push_back(c);
    } else {
      if (temp != "null") {
        try {
          op[index].result_ = std::stoi(temp);
        } catch (const std::exception &e) {
          std::cerr << e.what() << '\n';
          abort();
        }
      }
      temp.clear();
      ++index;
    }
  }

  if (temp != "null") {
    try {
      op[index].result_ = std::stoi(temp);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      abort();
    }
  }
}

TEST_CASE("min_stack") {

  auto test_case_1 = parse_case(
      R"(["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]])");
  parse_expect_result(test_case_1, R"([null,null,null,null,-3,null,0,-2])");

  auto test_case_2 = parse_case(
      R"(["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]])");
  parse_expect_result(test_case_2,
                      R"(
[null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483648,-2147483648,null,2147483647])");

  auto test_case_3 = parse_case(
      R"(["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
      [[],[2],[0],[3],[0],[],[],[],[],[],[],[]])");
  parse_expect_result(test_case_3,
                      R"([null,null,null,null,null,0,null,0,null,0,null,2])");

  MinStack minstack;

  for (auto &op : test_case_1) {
    CHECK(op(minstack) == true);
  }

  for (auto &op : test_case_2) {
    CHECK(op(minstack) == true);
  }

  for (auto &op : test_case_3) {
    CHECK(op(minstack) == true);
  }
}