#include <sstream>
#include <iomanip>
#include "movie.h"

using namespace std;

std::set<std::string> Movie::keywords() const {
  return keywords_;
}

std::string Movie::displayString() const {
  string result;

  result = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return result;
}

void Movie::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}