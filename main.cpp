#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <map>

struct Users {
  int id;
  std::string Name;
};

struct Emails {
  int id;
  std::string address;
};

std::vector<Users> users = {{6, "Felix"},   {5, "Carla"},  {1993, "Atlas"},
                            {24, "Anibal"}, {1, "Aurora"}, {1995, "Geneve"}};
std::vector<Emails> emails = {{5, "carlasemail@gmail.com"},
                              {99, "someonelse@gmail.com"}};

std::map<int, std::pair<std::string, std::string>> Joiner() {

  std::map<int, std::pair<std::string, std::string>> result;

  for (auto const &user : users) {
    result.insert({user.id, std::pair(user.Name, "")});
  }
  for (auto const &email : emails) {
    auto iterator = result.find(email.id);
    if (iterator == result.end()) {
      result.insert({email.id, std::pair("", email.address)});
    } else {
      iterator->second.second = email.address;
    }
  }
  return result;
}

TEST(InnerJoin, MakeAJoin) {
  // Arrange

  // Act
  int expectedID = 5;
  std::string expectedName = "Carla";
  std::string expectedEmail = "carlasemail@gmail.com";
  std::map<int, std::pair<std::string, std::string>> result = Joiner();
  auto resultName = result.at(expectedID).first;
  auto resultEmail = result.at(expectedID).second;

  // Result
  EXPECT_EQ(resultName, expectedName);
  EXPECT_EQ(resultEmail, expectedEmail);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
