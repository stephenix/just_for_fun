#include <iostream>
#include <vector>
#include <set>
using namespace std;

int numUniqueEmails(vector<string>& emails) {
	set<string> st; 
	string temp;

	for (int i = 0; i < emails.size(); i ++) {
		string cur = emails[i];	
		int j;
		for (j = 0; j < cur.size() && cur[j] != '+'; j ++) {
			if (cur[j] != '.') {
				temp += cur[j];
			}
		}
		while (j < cur.size() && cur[j] != '@') {
			++ j;
		}
		temp += cur.substr(j, cur.size() - j);
		st.insert(temp);
		temp.clear();	
	}
	return st.size();
}

int main() {
	vector<string> vecs = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	int ret = numUniqueEmails(vecs);
	cout << ret << endl;
	return 0;
}
