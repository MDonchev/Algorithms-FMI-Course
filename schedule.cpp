#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
using lli = long long int;
struct Range {
  int start, end;
  bool operator<(const Range &rhs) const {
    return end != rhs.end ? end < rhs.end : start < rhs.start;
  }
};
template <typename T>
lli cntInvMerge(vector<T> &v, int left, int right, vector<T> &temp) {
  int middle = left + (right - left) / 2;
  int i = left, j = middle + 1, k = left;
  lli cnt = 0;
  while (i <= middle && j <= right) {
    temp[k++] = v[j] < v[i] ? (cnt += middle - i + 1, v[j++]) : v[i++];
  }
  while (i <= middle) {
    temp[k++] = v[i++];
  }
  while (j <= right) {
    temp[k++] = v[j++];
  }
  std::copy(temp.begin() + left, temp.begin() + k, v.begin() + left);
  return cnt;
}

template <typename T>
lli cntInvMergeSort(vector<T> &v, int left, int right, vector<T> &temp) {
  if (left >= right) {
    return 0;
  }
  int middle = left + (right - left) / 2;
  lli invcnt = cntInvMergeSort(v, left, middle, temp);
  invcnt += cntInvMergeSort(v, middle + 1, right, temp);
  invcnt += cntInvMerge(v, left, right, temp);
  return invcnt;
}
int getMaxEvents(vector<Range> &events) {
  int count = 0;
  if (!events.empty()) {
    count++;
    Range last = events[0];
    for (int i = 1; i < events.size(); i++) {
      if (last.end <= events[i].start) {
        last = events[i];
        count++;
      }
    }
  }
  return count;
}
void schedule() {
  vector<Range> events, temp;
  Range current;
  int duration;
  while (scanf("%d %d", &current.start, &duration) == 2) {
    current.end = current.start + duration;
    events.push_back(current);
  }
  temp.resize(events.size());
  cntInvMergeSort(events, 0, events.size() - 1, temp);
  printf("%d\n", getMaxEvents(events));
}
int main ()
{
    schedule();
    return 0;
}
