#include "header.h"

/*
* 移动所有0到末尾，保持其他元素顺序不变
*/
template <class T> requires std::forward_iterator<typename T::iterator>&& std::integral<typename T::value_type>
void move_zero(T& t) {
	auto target = t.begin();
	/*
	auto begin = target;
	while (begin != t.end()) {
		if (*begin == 0) {
			++begin;
		}
		else {
			*target = *begin;
			++target;
			++begin;
		}
	}
	*/
	for (auto begin = target; begin != t.end(); ++begin) {
		if (!(*begin == 0)) {
			*target = *begin;
			++target;
		}
	}
	std::fill(target, t.end(), 0);
}

void test_move_zero() {
	auto a = std::to_array<int>({ 0, 1, 2, 3, 4, 0, 1 });
	move_zero(a);
	for (auto i : a) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}