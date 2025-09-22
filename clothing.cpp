#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

std::set<std::string> Clothing::keywords() const {
  return keywords_;
}

std::string Clothing::displayString() const {
  string result;

  result = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return result;
}

void Clothing::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}