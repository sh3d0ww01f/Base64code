#include "base64.h"
#include <iostream>
using namespace std;
int main() {
	string raw = "123456";
	cout << "encoded data:" << base64encode(raw) << endl;
	return 0;
}

