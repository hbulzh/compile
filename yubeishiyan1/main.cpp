#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct wenfa{
    set<char> Vn;
    set<char> Vt;
    char S = 'S';
    set<string> P;
}G;
set<char>::iterator c_ite,c_ite1;
set<string>::iterator s_ite;
string::iterator str_it;
void deal(char S){

}
int main()
{

    freopen("g.txt","r",stdin);
    string temp;
    char c;
    while(getline(cin,temp)){
       temp.erase(temp.find(';'));
        G.P.insert(temp);
        G.Vn.insert(temp[0]);
        for(int i = 0; i < temp.size(); i++)
            if('a' <= temp[i] || temp[i] <= 'z')
                G.Vt.insert(temp[i]);
        temp = "";
    }
    queue<char> que;
    c_ite = find(G.Vn.begin(),G.Vn.end(),G.S);
    if(c_ite != G.Vn.end()){
        que.push(G.S);G.Vn.erase(c_ite);
    };

    while(!que.empty()){
            bool flag = false;
        char start = que.front(); que.pop();
        cout << start << "->";
        for(s_ite = G.P.begin(); s_ite != G.P.end(); s_ite++){
            if((*s_ite)[0] == start){
                string temp = (*s_ite).substr((*s_ite).find('>')+1);
                if(flag) cout << '|';
               cout << temp; flag = true;
               for(int i = 0; i < temp.size(); i++)
                    if('A' <= temp[i] && temp[i] <= 'Z'){
                        c_ite1 = find(G.Vn.begin(), G.Vn.end(),temp[i]);
                        if(c_ite1 != G.Vn.end()){
                            que.push(*c_ite1);G.Vn.erase(c_ite1);
                        }
                    }

            }
        }
        cout << ";"<< endl;
    }

    return 0;
}
