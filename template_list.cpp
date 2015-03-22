#include <iostream>

using namespace std;
struct null
{
	typedef null head;
	typedef null tail;
};

template <typename H, typename T>
struct list
{
	typedef H head;
	typedef T tail;
};

template <typename l>
struct Length
{
	static const int result = 1 + Length<typename l::tail>::result;
};

template <> struct Length<null>
{
	static const int result = 0;
};

template <typename element, typename l>
struct Push
{
	typedef list<element, l> result;
};

template <typename l>
struct Pop
{
	typedef typename l::tail result;
};

template <int N> struct item { static const int result = N; };

int main() 
{
	typedef list<item<5>, list<item<6>,null> > l;
	typedef list<item<5>, list<item<6>, list<item<7>,null> > > m;
	typedef Push<item<4>, m> n;
	typedef Pop<n::result> o;
	cout << "Setup:" << endl;
	cout << "l: 5,6" << endl;
	cout << "m: 5,6,7" << endl;
	cout << "n: Push(4, m)" << endl;
	cout << "o: Pop(n)" << endl;
	cout << "Results:" << endl;
	cout << "Head(n): " << n::result::head::result << endl;
	cout << "Head(o): " << o::result::head::result << endl;
	cout << "Head(l): " << l::head::result << endl;
	cout << "Head(Tail(l)): " << l::tail::head::result << endl;
	cout << "Length(l): " << Length<l>::result << endl;
	cout << "Length(m): " << Length<m>::result << endl;
}
