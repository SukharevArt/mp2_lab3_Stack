
#include<string>

#include "HTStack.h"

int main() {
	/*TStack<int> a(20);
	for (int i = 1; i < 4; i++)
		a.push(i * 10);*/
	string s;
	getline(cin,s);
	TStack<int> p(s.size());
	bool flag=1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			p.push(1);
		if (s[i] == ')') {
			if (p.empty()) {
				flag = 0;
				break;
			}
			p.pop();
		}
	}
	flag = min(flag, p.empty());
	cout << (flag ? "CBS" : "NotCBS") << "\n";

}