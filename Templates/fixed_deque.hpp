#pragma once

#include <array>
#include <cstddef>
#include <utility>

template<class T, std::size_t Capacity>
class fixed_deque {
    static_assert(Capacity > 0);

public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;

    [[nodiscard]] constexpr bool empty() const noexcept { return m_head == m_tail; }
    [[nodiscard]] constexpr bool full() const noexcept { return next(m_tail) == m_head; }
    [[nodiscard]] constexpr size_type size() const noexcept {
        return m_tail >= m_head ? m_tail - m_head : storage_capacity - (m_head - m_tail);
    }

    template<class Self> constexpr auto&& front(this Self&& self) noexcept { return self.storage_[self.m_head]; }
    template<class Self> constexpr auto&& back(this Self&& self) noexcept { return self.storage_[previous(self.m_tail)]; }

    template<class U> constexpr void push_back(U&& value) {
        storage_[m_tail] = std::forward<U>(value);
        m_tail = next(m_tail);
    }
    template<class U> constexpr void push_front(U&& value) {
        const auto head = previous(m_head);
        storage_[head] = std::forward<U>(value);
        m_head = head;
    }
    template<class... Args> constexpr T& emplace_back(Args&&... args) {
        auto& slot = storage_[m_tail];
        slot = T(std::forward<Args>(args)...);
        m_tail = next(m_tail);
        return slot;
    }
    template<class... Args> constexpr T& emplace_front(Args&&... args) {
        const auto head = previous(m_head);
        auto& slot = storage_[head];
        slot = T(std::forward<Args>(args)...);
        m_head = head;
        return slot;
    }

    constexpr void pop_front() noexcept { m_head = next(m_head); }
    constexpr void pop_back() noexcept { m_tail = previous(m_tail); }
    constexpr void clear() noexcept { m_head = 0, m_tail = 0; }

private:
    static constexpr size_type storage_capacity = Capacity + 1;

    static constexpr size_type next(size_type index) noexcept {
        return index + 1 == storage_capacity ? 0 : index + 1;
    }
    static constexpr size_type previous(size_type index) noexcept {
        return index == 0 ? storage_capacity - 1 : index - 1;
    }

    std::array<T, storage_capacity> storage_{};
    size_type m_head = 0;
    size_type m_tail = 0;
};