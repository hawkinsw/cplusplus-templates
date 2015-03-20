#include <iostream>
#include <stdlib.h>

using namespace std;

int iff(bool t) {
	if (t) {
		cout << "true" << endl;
		return 1;
	}
	return 0;
}

template <bool b>
/*inline*/ int IF(void) {
	if (b) {
		cout << "true" << endl;
		return 1;
	}
	return 0;
}
int main() {
	int ret = 0;
	//ret = IF<true>();
	//return ret && IF<false>();
	ret = iff(true);
	return ret && iff(false);
}
