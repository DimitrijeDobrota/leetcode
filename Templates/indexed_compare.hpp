#pragma once

#include <cstddef>
#include <functional>
#include <utility>

template<class Range, class Comp = std::less<>>
class indexed_compare {
public:
    // The referenced range must outlive the comparator.
    constexpr explicit indexed_compare(const Range& values, Comp comp = {})
        : m_comp(std::move(comp)), m_values(values) {}

    constexpr bool operator()(std::size_t lhs, std::size_t rhs) const {
        return m_comp(m_values[lhs], m_values[rhs]);
    }

private:
    [[no_unique_address]] Comp m_comp;
    const Range& m_values;
};

template<class Range> using indexed_less = indexed_compare<Range, std::less<>>;
template<class Range> using indexed_less_equal = indexed_compare<Range, std::less_equal<>>;
template<class Range> using indexed_greater = indexed_compare<Range, std::greater<>>;
template<class Range> using indexed_greater_equal = indexed_compare<Range, std::greater_equal<>>;
template<class Range> using indexed_equal_to = indexed_compare<Range, std::equal_to<>>;
template<class Range> using indexed_not_equal_to = indexed_compare<Range, std::not_equal_to<>>;
