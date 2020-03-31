#pragma once

#include <cstdlib>
#include <utility>
#include <functional>

/**
 * Functional object, std::pair hash calculator
 */
struct FHashPair {
    /**
     * Get hash of std::pair as [std::hash(pair_obj.first) ^ std::hash(pair_obj.second)]
     * @tparam T1 Type of pair first argument
     * @tparam T2 Type of pair second argument
     * @param p Pair to hash
     * @return Hash of pair
     */
    template <typename T1, typename T2>
    size_t operator()(const std::pair<T1, T2>& p) const noexcept {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
