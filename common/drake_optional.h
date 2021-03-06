#pragma once

// Xcode has a broken std::experimental::optional, so we explicitly disable it.
// We can nix this code once github.com/tcbrindle/cpp17_headers/pull/12 merges.
#if defined(__APPLE__) && !defined(STX_NO_STD_OPTIONAL)
#define STX_NO_STD_OPTIONAL
#endif

#include <stx/optional.hpp>

/// @file
/// Provides drake::optional as an alias for the appropriate implementation of
/// std::optional or std::experimental::optional or stx::optional for the C++
/// toolchain being used.  (The alias is selected preferentially in that order,
/// so the most widely-compatible implementation will always be used.)

namespace drake {

template <typename T>
using optional = stx::optional<T>;

constexpr auto nullopt = stx::nullopt;

}  // namespace drake
