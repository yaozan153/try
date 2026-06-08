#include<iostream>
#include<string>
#include<ctype.h> 
using namespace std;
int main(){
    string a;
	getline(cin,a);
	string b;
	for(auto i:a)
	{
		if(isalpha(i)) b+=toupper(i);
	}
	bool isEmpty;
	if(b.empty()) isEmpty = true;
	else isEmpty = false;
	cout << b << endl;
	cout << isEmpty;
    return 0;
}
