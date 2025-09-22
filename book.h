#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product {
public:
    using Product::Product;
    
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
    std::string isbn_;
    std::string author_;
    std::set<std::string> keywords_;
};
#endif