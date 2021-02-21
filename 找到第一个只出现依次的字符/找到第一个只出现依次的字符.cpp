/**
 给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出"no"。

输入格式
一个字符串，长度小于 100000100000。

输出格式
输出第一个仅出现一次的字符，若没有则输出"no"。

输出时每行末尾的多余空格，不影响答案正确性

样例输入
abcabd
样例输出
c
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

struct info {
	char letter;
	int firstIndex = -1;
	int count = 0;
};

void fun01() {
	char str[100000] = { '0' };
	map<char, info> m;
	cin >> str;
	int length = strlen(str);
	for (int i = 0; i < length; ++i) {
		char key = str[i];
		auto it = m.find(key);
		if (it == m.end()) {
			info temp;
			temp.firstIndex = i;
			temp.letter = key;
			++temp.count;
			m.insert(make_pair(key, temp));

		}
		else {
			it->second.count++;
		}
	}
	vector<info> v;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second.count == 1) {
			v.push_back(it->second);
		}
	}
	if (v.empty()) {
		cout << "no";
		return;
	}
	sort(v.begin(), v.end(), [=](const info& i1, const info& i2)->bool {
		return i1.firstIndex < i2.firstIndex;
		});

	cout << v.front().letter;

	//for (auto it = v.begin(); it != v.end(); ++it) {
	//	cout << "字符:" << it->letter << ",位置:" << it->firstIndex << "出现次数:" << it->count << endl;
	//}
}

/*
您的程序没有在限定时间内执行完，
它在执行我们的测试用例的时候超过了我们设定的时间界限，
所以我们终止了您的程序。请检查程序中是否存在死循环，
或设计时间复杂度更低的算法。
 */
void fun02() {
	char str[100000] = { '0' };
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len - 1; ++i) {
		char c = str[i];
		int count = 1;
		for (int j = i + 1; j < len; ++j) {
			if (c == str[j]) {
				++count;
			}
		}
		if (count == 1) {
			cout << c;
			return;
		}
	}
	cout << "no";
}

int main(int argc, char* argv[]) {
	fun01();

	//fun02();


	return 0;
}
