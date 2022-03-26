#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> key_indices;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == key) {
        key_indices.push_back(i);
      }
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      auto iter = find_if(key_indices.begin(), key_indices.end(), [i, k](int ki) {
        return abs(i - ki) <= k;
      });
      if (key_indices.end() != iter) {
        result.push_back(i);
      }
    }

    return result;
  }
};

void TestFindKDistantIndices() {
  Solution s;
  {
    vector<int> nums{3, 4, 9, 1, 3, 9, 5};
    vector<int> expected{1, 2, 3, 4, 5, 6};
    assert(expected == s.findKDistantIndices(nums, 9, 1));
  }
  {
    vector<int> nums{2, 2, 2, 2, 2};
    vector<int> expected{0, 1, 2, 3, 4};
    assert(expected == s.findKDistantIndices(nums, 2, 2));
  }
  {
    vector<int> nums{1};
    vector<int> expected{0};
    assert(expected == s.findKDistantIndices(nums, 1, 1));
  }
}

int main() {
  TestFindKDistantIndices();
  std::cout << "Ok!" << std::endl;
  return 0;
}
