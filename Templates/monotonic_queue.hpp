#pragma once

#include <functional>
#include "fixed_deque.hpp"

template<class T, std::size_t Capacity, class Comp = std::less<T>>
class monotonic_queue {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;

    constexpr explicit monotonic_queue(Comp comp = {}) : m_comp(std::move(comp)) {}

    [[nodiscard]] constexpr bool empty() const noexcept { return m_deque.empty(); }
    [[nodiscard]] constexpr bool full() const noexcept { return m_deque.full(); }
    [[nodiscard]] constexpr size_type size() const noexcept { return m_deque.size(); }

    template<class Self> constexpr auto&& front(this Self&& self) noexcept { return self.m_deque.front(); }

    // Discard dominated candidates; pop() removes the front candidate, not the oldest input.
    constexpr void push(T elem) {
        while (!m_deque.empty() && m_comp(elem, m_deque.back())) {
            m_deque.pop_back();
        }
        m_deque.push_back(std::move(elem));
    }

    constexpr void pop() noexcept { m_deque.pop_front(); }
    constexpr void clear() noexcept { m_deque.clear(); }

private:
    [[no_unique_address]] Comp m_comp;
    fixed_deque<T, Capacity> m_deque;
};
