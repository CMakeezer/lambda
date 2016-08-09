
#pragma once

#include "stream.hpp"

namespace lambda {
namespace streams {

template <class S, class F>
class FilterStream : public Stream {
    S stream;
    F fn;

public:
    using Type = typename S::Type;

    FilterStream(S stream, F fn) : stream(stream), fn(fn) {}

    Maybe<Type> next() {
        while (auto s = std::move(stream.next())) {
            if (fn(std::cref(*s))) {
                return s;
            }
        }
        return none;
    }
};

template <class F>
class Filter : public Pipeable {
    F f;

public:
    Filter(F f) : f(f) {}

    template <class S>
    auto operator()(S stream) const {
        return FilterStream<S, F>{stream, f};
    }
};

template <class F>
auto filter(F &&f) {
    return Filter<F>{std::forward<F>(f)};
}

} /* streams */
} /* lambda */