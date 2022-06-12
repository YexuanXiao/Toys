#include "header.h"

/*
* 将一个非递减数组填充到另一非递减数组，保持非递减
*/
template <class T> requires std::random_access_iterator<typename T::iterator>&& std::integral<typename T::value_type>
void add_array(T& left, const T& right) {
	std::ptrdiff_t lsize = left.size();
	std::ptrdiff_t rsize = right.size();
	left.resize(lsize + rsize);
	std::ptrdiff_t length = lsize + rsize;
	--lsize, --rsize, --length;
	while (length > -1) {
		if (rsize < 0) {
			break;
		}
		else if (lsize < 0) {
			left[length] = right[rsize];
			--rsize;
		}
		else if (left[lsize] > right[rsize]) {
			left[length] = left[lsize];
			--lsize;
		}
		else {
			left[length] = right[rsize];
			--rsize;
		}
		
		--length;
	}
}

void test_add() {
	auto a = std::vector<int>{ 2,3,4};
	auto b = std::vector<int>{ 0,1,4 };
	add_array(a, b);
	for (auto c : a) {
		std::cout << c << ' ';
	}
	std::cout << std::endl;
}