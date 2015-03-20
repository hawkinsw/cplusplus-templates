#include <iostream>
#include <string>

using namespace std;

template<typename T, bool b>
void check_result(const T &t) 
{
	if (b) {
		if(!t)
			cerr<<"Failed in check_results with t="<<t<<endl;
	}
}

template<class T> void check_result_orig(const T& t)
{
	if (!t)
		cerr<<"Failed in check_results with t="<<t<<endl;
}

/*
 * This is explicit instantiation.
 */
template
void check_result<int, true>(const int &t);

/*
 * This is specialization.
 */
template<>
void check_result<string,true>(const string &t)
{
	if (t.empty())
		cerr << "empty string." << endl;
}
template<>
void check_result<string,false>(const string &t)
{
}

int main()
{
	int i = 0;
	check_result<int, true>(i++);
	check_result<int, false>(i++);
	/*
	check_result_orig<int>(i++);
	check_result_orig<int>(i++);
	*/
	cout << "i: " << i << endl;

	//check_result<string, false>("");

	return 0;
}
