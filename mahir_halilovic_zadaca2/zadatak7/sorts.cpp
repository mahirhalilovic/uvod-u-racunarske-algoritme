#include <algorithm>

template<typename S, typename C>
void quicksort(S* timovi, int size, C comp) {
  if(size > 1) {
    auto last = timovi[size - 1].bodovi;
    auto pivot = std::partition(timovi, [](auto lhs, auto rhs) { return lhs.bodovi < rhs.bodovi; });
    
    std::swap(last, *pivot);
    auto mid = pivot - timovi;
    quicksort(timovi, mid, comp);
    quicksort(timovi + mid + 1, size - mid, comp);
  }
}

template<typename S, typename C>
void merge(S* timovi, int mid, int size, C comp) {
  auto mid2 = mid + 1;
  int start = 0;
  while(start != mid && mid2 != size) {
    if(timovi[start] <= timovi[mid2])
      ++start;
    else {
      auto key = timovi[mid2];
      auto i = mid;

      while(i > 0) {
        timovi[i] = timovi[i--];
      }

      timovi[0] = key;
      ++start;
      ++mid2;
    }
  }
}

template<typename S, typename C>
void mergesort(S* timovi, int size, C comp) {
  if(size > 1) {
    auto mid = size / 2;
    mergesort(timovi, mid, comp);
    mergesort(timovi + mid + 1, size - mid, comp);
  }
}
