#include "header.h"

/*
* 找到n长度，范围1-n的数组中，缺失的数
* 例：4，3，2，7，8，2，3，1中，缺失5和6
* 思路1：排序再查找
* 思路2：由于范围n同时可以作为数组下标，所以可以通过值标记下标，若某个下标的值未被标记，说明该下标值缺失
* 思路2.1：若所有数大于0，且有符号：将值减1进行寻址，将寻址得到的值求负
* 思路2.2：若无符号，且2n小于(value_type_MAX+1)/2，则寻址后可将所有数加n(无符号溢出则回绕)
* 思路2.3：若有符号，且2n小于(value_type_MAX+1)/4则可使用2.2
* 思路2.4：利用辅助bool数组
*/
template <class T> requires forward_iterator<typename T::iterator>&& std::integral<typename T::value_type>
auto find_lost(const T& t) {
	auto assist = std::vector<char>(size, 1);
	auto data = assist.data();
	for (auto begin = t.begin(), end = t.end(); begin != end; ++begin) {
		data[(*begin) - 1] = 0;
	}
	return assist;
}
void test_find_lost() {
	std::vector<int> a{ 4,3,2,7,8,2,3,1 };
	auto res = std::move(find_lost(a));
	for (auto i : res) {
		std::cout << i + '0' << ' ';
	}
	std::cout << std::endl;
}