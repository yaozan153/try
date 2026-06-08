#include<iostream>
using namespace std;
void swap(int &a,int &b){ //引用&，形参就像是对应实参的别名。 
    int t=a;
    a=b;
    b=t;
}//利用引用访问，实现实参交换 
void swapjia(int a,int b){//只有形参交换，没有实参交换 
    int t=a;
    a=b;
    b=t;
}
int main()
{
	int a = 10;
	int &b = a;//可以理解为a把地址给了b
	//a，b都是指向某块内存里面的值 
	//“你们要抓鲁迅关我周树人什么事 ” 
	cout<<"a = "<<a<<endl; 
	cout<<"b = "<<b<<endl; 
	b = 20; 
	cout<<"a = "<<a<<endl; 
	cout<<"b = "<<b<<endl;
	
	system("pause");
	int x,y;
    cin>>x>>y;
    swap(x,y);
    cout<<x<<" "<<y<<endl;
    
    system("pause");
	return 0;
} 
