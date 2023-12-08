#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

namespace Mahir {

template <typename It>
It linear_search(It begin, It end, typename It::value_type value, bool sorted = false) {
  if (sorted) {
    while (begin != end && *begin <= value) {
      if (*begin == value) return begin;

      ++begin;
    }
  } else {
    while (begin != end) {
      if (*begin == value) return begin;

      ++begin;
    }
  }

  return end;
}

template <typename It>
It binary_search(It begin, It end, typename It::value_type value) {
  const auto cend = end;
  int n = end - begin;
  while(n > 0) {
    auto mid = begin + n / 2;
    if(*mid == value) return mid;
    else if(*mid > value) end = mid;
    else begin = mid + 1;

    n /= 2;
  }

  return cend;
}

template <typename It>
void bubble_sort(It begin, It end) {
  const auto cend = --end;
  const auto cbegin = begin;

  while(begin != cend) {
    bool sorted = true;
    for(auto it = cbegin; it != end;) {
      auto temp = it++;
      if(*it < *temp) {
        std::swap(*it, *temp);
        sorted = false;
      }
    }

    if(sorted) return;
  }
}

template<typename It>
void selection_sort(It begin, It end) {
  auto pos = begin++;
  while(begin != end) {
    auto min = pos;
    auto b = pos;
    ++b;
    for(; b != end; ++b)
      if(*b < *min) min = b;

    if(min != pos) std::swap(*min, *pos);

    ++pos;
    ++begin;
  }
}

template<typename It>
void insertion_sort(It begin, It end) {
  auto cnt = begin;
  --begin;
  ++cnt;

  while(cnt != end) {
    auto key = *cnt;
    auto temp = cnt++;
    auto ph = temp;
    --temp;

    while(temp != begin && *temp > key) {
      *ph = *temp;
      --temp;
      --ph;
    }

    *ph = key;
  }
}

template<typename It>
void shell_sort(It begin, It end) {
  int n = end - begin;
  for(int shell = n / 2; shell > 0; shell /= 2) {
    for(auto i = begin + shell; i != end; ++i)
      for(auto j = i; (j - begin) >= shell && *j < *(j - shell); j -= shell)
        std::swap(*j, *(j - shell));
  }
}

template<typename It>
void merge(It begin, It mid, It end) {
  const auto cmid = mid;
  const auto cbegin = begin;
  std::vector<typename It::value_type> temp;

  while(begin != cmid && mid != end) {
    if(*begin <= *mid) {
      temp.push_back(*begin);
      ++begin;
    } else {
      temp.push_back(*mid);
      ++mid;
    }
  }

  while(begin != cmid) {
    temp.push_back(*begin);
    ++begin;
  }
  while(mid != end) {
    temp.push_back(*mid);
    ++mid;
  }

  std::move(temp.begin(), temp.end(), cbegin);
}

template<typename It>
void merge_sort(It begin, It end) {
  int n = end - begin;
  if(n > 1) {
    auto mid = begin + n / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
  }
}

template<typename It>
void quick_sort(It begin, It end) {
  int n = end - begin;
  if(n > 1) {
    auto last = *(end - 1);
    auto pivot = std::partition(begin, end, [&last](auto lhs) { return lhs < last; });
    std::swap(*pivot, *(end - 1));
    quick_sort(begin, pivot++);
    quick_sort(pivot, end);
  }
}

}  // namespace Mahir
