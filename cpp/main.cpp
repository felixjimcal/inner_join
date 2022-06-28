#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

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

  assert(result.Name == expectedOuptut.Name);
  assert(result.Email == expectedOuptut.Email);
}


int main() {
  Users users[6] = {
      {0, "Felix"},  {1, "Carla"},  {2, "Atlas"},
      {3, "Anibal"}, {4, "Aurora"}, {5, "Geneve"},
  };

  Emails emails[2] = {{1, "carlasemail@gmail.com"},
                      {99, "someonelse@gmail.com"}};

  int id = 1;
  JoinedData result;

  // https://stackoverflow.com/questions/589985/vectors-structs-and-stdfind
  struct findUserData
  {
      int id;
      findUserData(int id) : id(id) {}
      bool operator () ( const Users& m ) const
      {
          return m.id == id;
      }
  };
  auto userData = std::find_if(std::begin(users), std::end(users), findUserData(id));

  struct findUserEmail
  {
      int id;
      findUserEmail(int id) : id(id) {}
      bool operator () ( const Emails& m ) const
      {
          return m.id == id;
      }
  };
  auto userEmail = std::find_if(std::begin(emails), std::end(emails), findUserEmail(id));

  result = {userData->id, userData->Name, userEmail->address};

  CheckJoin(result);
  return 0;
}
