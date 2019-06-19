#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
void E();
void T();
void E1();
void T1();
void F();
int IsDigit(string s);
string s;
int i, SIGN;
int main()
{
	int token = 1;
 freopen("1.txt","r",stdin);
 while(cin >> s)
 {
 	
 	printf("(%d) ",token++);
 	cout << s << "\n";
 	bool flag =true;
 	if(s[0] == '0') flag = false;
 	for(int i = 0; i < s.size()-1; ++i){
 		if(!isdigit(s[i])) flag = false;
	 }
	if(flag){
		cout << "输出：正确\n";
		continue;
	}
   SIGN = 0;
   	i=0;
   
   if( s[0] == ';')
     return 0;
   E();
   
   if(s[i]==';')
     printf("输出：正确\n");
   
 }
 return 1;
}
void E()
{
 if(SIGN==0)
 {
   T();
   E1();
 }
}
void E1()
{
 if(SIGN==0)
 {
   if(s[i]=='+')
   {
     ++i;
     T();
     E1();
   }
   else if(s[i]!=';'&&s[i]!=')')
   {
     printf("输出：错误\n");
     SIGN=1;
   }
 }
}
void T()
{
 if(SIGN==0)
 {
   F();
   T1();
 }
}
void T1()
{
 if(SIGN==0)
 {
   if(s[i]=='*')
   {
     ++i;
     F();
     T1();
   }
   else if(s[i]!=';'&&s[i]!=')'&&s[i]!='+')
   {
     printf("输出：错误\n");
     SIGN=1;
   }
 }
}
void F()
{
 if(SIGN==0)
 {
   if(s[i]=='(')
   {
     ++i;
     E();
     if(s[i]==')')
       ++i;
     else if(s[i]== ';')
     {
       printf("输出：错误\n");
       SIGN=1;
       ++i;
     }
   }
   else if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
     ++i;
   else
   {
     printf("输出：错误\n");
     SIGN=1;
    }
 }
}
int IsDight(string s){
	if(s[0] == '0') return false;
	for(int i = 0; i < s.size(); ++i){
		if(!isdigit(s[i])) return false;
	}
	return true;
}
