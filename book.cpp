#include <sstream>
#include <iomanip>
#include "book.h"

using namespace std;

std::set<std::string> Book::keywords() const {
  return keywords_;
}

std::string Book::displayString() const {
  string result;

  result = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return result;
}

void Book::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}