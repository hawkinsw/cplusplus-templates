#include <iostream>

using namespace std;

struct testing {
	short int a;
	int b;
	long int c;
};

struct testing2 {
	char a;
	int b;
	int* c;
};

template <typename S>
struct derived {
	S s;
	decltype(s.a) a;
	decltype(s.b) b;
	decltype(s.c) c;
};

int main() {
	struct derived<testing> d;
	struct derived<testing2> e;

	cout << "struct derived<testing> d:" << endl;
	cout << "sizeof(d.a): " << sizeof(d.a) << endl;
	cout << "sizeof(d.b): " << sizeof(d.b) << endl;
	cout << "sizeof(d.c): " << sizeof(d.c) << endl;
	
	cout << "struct derived<testing2> e:" << endl;
	cout << "sizeof(e.a): " << sizeof(e.a) << endl;
	cout << "sizeof(e.b): " << sizeof(e.b) << endl;
	cout << "sizeof(e.c): " << sizeof(e.c) << endl;
	return 0;
};
