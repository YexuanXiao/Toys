#include "header.h"

/*
* 问题：只能一次走一层或两层，走n层有多少种走法
* 算法分析：
* 思路1：使用排列组合，经简单尝试发现过于复杂，不可行。
* 思路2：当n为1时结果为1，当n为2时结果为2，当n>2时可转化为先走一步的情况和先走两步的情况的和，变为一个递归算法，然后进行尾递归化简
*/
auto climbStairs(std::integral auto n) {
	using T = decltype(n);
	T prv1 = 1;
	T prv2 = 2;
	T result = 3;

	if (n == 1) return prv1;
	if (n == 2) return prv2;
	for (T i = 3; i < n; ++i) {
		prv1 = result;
		result = result + prv2;
		prv2 = prv1;
	}
	return result;
}
void test_climb() {
	for (unsigned i = 1; i < 47; ++i) {// 无符号i>46时溢出
		std::cout << climbStairs(i) << std::endl;
	}
}

/*
* 可以改写成斐波那契数列
*/
auto fib(std::integral auto n) {
	using T = decltype(n);
	T prv1 = 0;
	T prv2 = 1;
	T result = 1;

	if (n == 0) return prv1;
	if (n == 1) return prv2;
	if (n == 2) return prv2;
	for (T i = 2; i < n; ++i) {
		prv1 = result;
		result = result + prv2;
		prv2 = prv1;
	}
	return result;
}

void test_fib() {
	for (unsigned i = 0; i < 48; ++i) {// 无符号i>47时溢出
		std::cout << fib(i) << std::endl;
	}
}