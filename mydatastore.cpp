#include <sstream>
#include <iomanip>
#include "mydatastore.h"

using namespace std;

MyDataStore::~MyDataStore() {
  for (std::set<Product*>::iterator it = product_.begin(); it != product_.end(); ++it) {
    delete *it;
  }
  product_.clear();

  for (std::map<std::string, User*>::iterator it = user_.begin(); it != user_.end(); ++it) {
    delete it->second;
  }
  user_.clear();
}

void MyDataStore::addProduct(Product* p) {
  product_.insert(p);
}

void MyDataStore::addUser(User* u) {
  user_[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::vector<Product*> results;
  std::set<std::string> temp;

  for (unsigned int i = 0; i < terms.size(); i++) {
    temp.insert(terms[i]);
  }

  if (terms.size() == 0) {
    return results;
  }

  if (type == 0) {

    for (std::set<Product*>::iterator it = product_.begin(); it != product_.end(); ++it) {
      std::set<std::string> keys = (*it)->keywords();

      if (setIntersection(temp, keys).size() == temp.size()) {
        results.push_back(*it);
      }
    }
    return results;
  }

  if (type == 1) {

    for (std::set<Product*>::iterator it = product_.begin(); it != product_.end(); ++it) {
      std::set<std::string> keys = (*it)->keywords();

      if (!setIntersection(temp,keys).empty()) {
        results.push_back(*it);
      }
    }
    return results;
  }

  return results;
}

void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << endl;

  for (std::set<Product*>::iterator it = product_.begin(); it != product_.end(); ++it) {
    (*it)->dump(ofile);
  }

  ofile << "</products>" << "\n" << "<users>" << endl;

  for (std::map<std::string, User*>::iterator it = user_.begin(); it != user_.end(); ++it) {
    it->second->dump(ofile);
  }

  ofile << "</users>" << endl;
}