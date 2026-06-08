#include<iostream>
#include<string>
using namespace std;
int main() {
string s = "sysu-computer";
int len = s.length();
const char* cs = s.c_str();
cout << s << " len is " 
<< len << endl;
return 0;
}
