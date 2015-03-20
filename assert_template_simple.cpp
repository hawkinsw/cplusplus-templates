#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

#undef NDEBUG

#ifdef NDEBUG
#define ASSERT true
#else
#define ASSERT false
#endif

template<typename T, bool b>
void check_result(const T &t) 
{
	if (b) {
		if(!t)
			cerr<<"Failed in check_results with t="<<t<<endl;
	}
}

int main()
{
	int i = 0;
	check_result<int, ASSERT>(i++);
	check_result<int, ASSERT>(i++);
	if (i != 2)
		cout << "This does not actually work." << endl;
	else
		cout << "This does actually work." << endl;
	return 0;
}
