/*
~ Author    : @tridib_2003
~ Title     : SBSTR1 - Substring Check (Bug Funny)
~ Link      : https://www.spoj.com/problems/SBSTR1/
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        string s1,s2;
        cin>>s1>>s2;
        int g=0;
        for(int i=0;i<s1.size()-4;i++) {
            string ss = s1.substr(i,5);
            if(ss == s2) {
                g = 1;
                break;
            }
        }
        if(g)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
	return 0;
}
