#include "base64.h"
std::string Base64Code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int gcd(int a, int b) {
	if (a < b) { int temp1 = a; a = b; b = temp1; }
	while (b != 0) { int temp2 = b; b = a % b; a = temp2; }
	return a;
}
std::string base64encode(std::string raw) {
	bool* ret;
	std::vector<bool> rawBin;
	std::string  encoded = "";
	for (auto i = raw.begin(); i != raw.end(); i++) {
		ret = new bool[8];
		memset(ret, 0, 8);
		auto tmp = 7;
		int num = *i;
		while (num > 0) {
			ret[tmp--] = num % 2;
			num /= 2;
		}
		for (int i = 0; i < 8; i++) {
			rawBin.push_back(ret[i]);
		}
	}
	int currentLength = rawBin.size() % 6;
	if (currentLength != 0) {
		int  tmp = 2 + currentLength % 6;
		int zero = 6 - (currentLength) + (6 * (2 + currentLength % 6)) / (gcd(currentLength, 6));
		for (int i = 0; i < zero; i++) {
			rawBin.push_back(0);
		}
	}
	for (auto i = rawBin.begin(); i != rawBin.end(); i += 6) {
		int tmp = 0; 
		for (auto j = i; j != i + 6; j++) {
			tmp = tmp * 2 + !!(*j);
		}
		if (tmp == 0) {
			encoded += Base64Code[64];
		}
		else {
			encoded += Base64Code[tmp];
		}
	}
	return encoded;
}
std::string base64decode(std::string raw) {
	bool* ret;
	std::vector<bool> rawBin;
	std::string  decoded = "";
	for (auto i = raw.begin(); i != raw.end(); i++) {
		int num = Base64Code.find(*i);
		int tmp = 5;
		bool* ret = new bool[6];
		memset(ret, 0, 6);
		while (num > 0) {
			ret[tmp--] = num % 2;
			num /= 2;
		}
		for (int i = 0; i < 6; i++) {
			rawBin.push_back(ret[i]);
		}
	}
	for (auto i = rawBin.begin(); i != rawBin.end(); i += 8) {
		int tmp = 0;
		for (auto j = i; j != i + 8; j++) {
			tmp = tmp * 2 + !!(*j);
		}
		if (tmp == 0) {
			decoded += "";
		}
		else {
			decoded += tmp;
		}
	}
	return decoded;
}
