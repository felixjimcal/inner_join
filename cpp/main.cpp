#include <algorithm>
#include <iostream>
#include <assert.h>

struct Users {
  int id;
  std::string Name;
};

struct Emails {
  int id;
  std::string address;
};

struct JoinedData {
  int id;
  std::string Name;
  std::string Email;
};

void CheckJoin(JoinedData result) {
  JoinedData expectedOuptut{1, "Carla", "carlasemail@gmail.com"};

  assert(result.id == expectedOuptut.id);
  assert(result.Name == expectedOuptut.Name);
  assert(result.Email == expectedOuptut.Email);
}

int main() {
  Users users[6] = { {0, "Felix"},  {1, "Carla"},  {2, "Atlas"}, {3, "Anibal"}, {4, "Aurora"}, {5, "Geneve"} };

  Emails emails[2] = { {1, "carlasemail@gmail.com"}, {99, "someonelse@gmail.com"}};

  auto matchUser = std::find_if(std::begin(users), std::end(users), [](const Users &mu) { return mu.id == 1; });
  auto matcEmail = std::find_if(std::begin(emails), std::end(emails), [](const Emails &me) { return me.id == 1; });

  JoinedData result;
  if (matchUser != std::end(users) && matcEmail != std::end(emails)) {
    result = {matchUser->id, matchUser->Name, matcEmail->address};
  }

  CheckJoin(result);

  return 0;
}
