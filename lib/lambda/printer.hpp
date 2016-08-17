
#pragma once

#include <iostream>

#include "show.hpp"

namespace lambda {

class Printer {
public:
    static Printer get() {
        static Printer p;
        return p;
    }

    Printer() = default;

    Printer &operator<<(std::string s) {
        std::cout << s;
        return *this;
    }
};

static auto printer = Printer::get();

template <class T>
Printer &operator<<(Printer &os, const T value) {
    os << show(value);
    return os;
}

} /* lambda */
