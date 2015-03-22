#include <iostream>

using namespace std;

template <int n>
struct summation
{
	static const int value = n + summation<n-1>::value;
};
template <> struct summation<0>
{
	static const int value = 1;
};
/*
 * explicit instantiation.
 */
template struct summation<5>;

int main() {
	cout << "summation<5>: " << summation<5>::value << endl;
	return 0;
}
