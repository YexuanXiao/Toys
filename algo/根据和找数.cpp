#include "header.h"

/*
* 根据两数之和找出两数，先排序再二分查找，空间复杂度 O(1)
*/
template <class T> requires std::random_access_iterator<typename T::iterator>&& std::integral<typename T::value_type>
auto sum_find(const T& nums, typename T::value_type target) {
	std::sort(nums.begin(), nums.end());
	using value_type = T::value_type;
	for (auto a = nums.begin(); a != nums.end(); ++a) {
		for (auto start = a, end = nums.end(); start != end && start != end - 1;) {
			auto mid = end - (end - start) / 2;
			auto diff = target - *a;
			if (diff > *mid) {
				start = mid;
			}
			else if (diff < *mid) {
				end = mid;
			}
			else {
				auto res = std::pair<value_type, value_type>{ *a,*mid };
				return res;
			}
		}
	}
}

void test_sum() {
	std::vector<int> a{ 7,9,10,12,13,16,21 };
	auto res = sum_find(a, 22);
	std::cout << res.first << ' ' << res.second << std::endl;
	std::vector<int> b{ 7,9,10,12,13,16,21 };
	res = sum_find(b, 19);
	std::cout << res.first << ' ' << res.second << std::endl;
}