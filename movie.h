#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Movie : public Product {
public:
    using Product::Product;
    
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
    std::string genre_;
    std::string rating_;
    std::set<std::string> keywords_;
};
#endif