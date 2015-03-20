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

template <bool b>
struct _if
{
template <typename T, typename F, const T *t, const F *f>
struct result 
{
	/*
	 * Constexpr required here and below 
	 * because the pointers (though they are
	 * actually constant) are not integral types.
	 * 'static const' initialization is only
	 * allowed with integral types. constexpr
	 * changed that in c++11. Must compile with
	 * -std=c++11 for this to work.
	 */
	constexpr static const T *value = t;
};
};

template <>
struct _if<false>
{
template <typename T, typename F, const T *t, const F *f>
struct result 
{
	constexpr static const F *value = f;
};
};

/*
 * explicit instantiation.
 */
template struct summation<5>;

/*
 * For _if to work, these must have "static"
 * external linkage. Or maybe internal linkage,
 * but I don't know how to do that.
 */
int one;
string false_;
string true_;
int main() {

	one = 1;
	false_ = "false";
	true_ = "true";

	cout << "summation<5>: " << summation<5>::value << endl;

	cout << "_if<false, \"true\", \"false\">: "
	     << *(_if<false>::result<string, string, &true_, &false_>::value) << endl;
	cout << "_if<true, \"true\", \"false\">: "
	     << *(_if<true>::result<string, string, &true_, &false_>::value) << endl;
	cout << "_if<true, 1, \"false\">: "
	     << *(_if<true>::result<int, string, &one, &false_>::value) << endl;
	return 0;
}
