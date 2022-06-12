#include "header.h"

template<typename T>
concept character = std::same_as<T, char> || std::same_as<T, unsigned char> || std::same_as<T, signed char> || std::same_as<T, wchar_t> || std::same_as<T, char16_t> || std::same_as<T, char8_t> || std::same_as<T, char32_t>;
/*
* 字符串解码
* 例1：3[a]2[bc] -> aaabcbc
*
* 例2：3[a2[c]] -> accaccacc
* 分析：
* 1. 每次遇到 ] 都是一个输出过程
* 2. 字符串遇到数字和 ] 时停止
*/
template<class T> requires std::input_iterator<typename T::iterator> && character<typename T::value_type>
auto decode_pattern(const T& input) {
	using value_type = typename T::value_type;
	using string_ = std::basic_string<value_type>;
	std::stack<short> opr{};// 乘数栈
	std::stack<string_> opd;// 字符串栈
	string_ res{};// 结果
	string_ temp{};// 每一节字符串
	for (auto begin = input.cbegin(), end = input.cend(); begin != end; ++begin) {
		auto current = *begin; // 当前字符
		if (current == '['); // 左括号无意义
		else if (current == ']') {
			if (!temp.empty()) { // 将字符串入栈
				opd.push(std::move(temp));
			}
			auto mult = opr.top(); // 倍数
			opr.pop();
			res = opd.top(); // 按倍数重复字符串
			for (int i = 1; i < mult; ++i) {
				res += opd.top();
			}
			opd.pop(); // 出栈
			if (!opd.empty()) { // 此时若操作数栈不为空，则将栈内操作数和res合并
				temp = std::move(opd.top());
				opd.pop();
				temp += res;
				std::swap(res, temp);
				temp.clear();
			}
			opd.push(res); // 将结果入栈
		}
		else if (current > '9' || current < '0') {
			temp.push_back(current); // 将字符累加为字符串
		}
		else { // 此时是数字
			if (!temp.empty()) {// 将字符串入栈
				opd.push(std::move(temp));
			}
			opr.push(current - '0');
		}
	}
	return res;
}

void test_decode_pattern() {
	std::string a{ "3[a]2[bc]" };
	std::string b{ "3[a2[c]]" };
	std::string result = std::move(decode_pattern(a));
	std::cout << result << std::endl;
	result = std::move(decode_pattern(b));
	std::cout << result << std::endl;
}