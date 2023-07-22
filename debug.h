#ifndef INIT_H
#define INIT_H
#include <bits/stdc++.h>
using namespace std;
#ifdef ATCODER_ALL
    #include <atcoder/all>
    using namespace atcoder;
#endif
string debug;
#define CNT 50
#define show(x) debug="";cerr<<# x<<" = "<<(sub((x))>1?"\n":"")<<debug<<"\n";
#define show_(x) debug="";cerr<<# x<<" = "<<(sub((x))>1?"\n":"")<<debug<<", ";
#define show2(x,y) show_(x);show(y);
#define show3(x,y,z) show_(x);show_(y);show(z);
#define show4(w,x,y,z) show_(w);show_(x);show_(y);show(z);
#define show5(v,w,x,y,z) show_(v);show_(w);show_(x);show_(y);show(z);
#define show6(u,v,w,x,y,z) show(u);show_(v);show_(w);show_(x);show_(y);show(z);
#define show7(t,u,v,w,x,y,z) show_(t);show(u);show_(v);show_(w);show_(x);show_(y);show(z);
#define show8(s,t,u,v,w,x,y,z) show_(s);show_(t);show(u);show_(v);show_(w);show_(x);show_(y);show(z);
#define show9(r,s,t,u,v,w,x,y,z) show_(r);show_(s);show_(t);show(u);show_(v);show_(w);show_(x);show_(y);show(z);

string padding(string x);
int sub(const string x);
//int sub(const string x);
int sub(const char* x);
int sub(const bool x);
#ifdef ATCODER
int sub(modint x);
int sub(modint1000000007 x);
int sub(modint998244353 x);
#endif
template<class T>int sub(vector<T>x);
template<class T>int sub(set<T> x);
template<class T,class U>int sub(pair<T,U>x);
template<class T>int sub(tuple<T>x);
template<class T,class U> int sub(tuple<T,U>x);
template<class T,class U,class V>int sub(tuple<T,U,V>x);
template<class T,class U,class V,class W>int sub(tuple<T,U,V,W>x);
template<class T,class U,class V,class W, class X>int sub(tuple<T,U,V,W,X>x);
template<class T,class U,class V,class W, class X, class Y>int sub(tuple<T,U,V,W,X,Y>x);
template<class T,class U,class V,class W, class X, class Y, class Z>int sub(tuple<T,U,V,W,X,Y,Z>x);
template<class T>int sub(queue<T>x);
template<class T>int sub(priority_queue<T>x);
template<class T>int sub(priority_queue<T,vector<T>,greater<T>>x);
template<class T>int sub(vector<T>x);
template<class T>int sub(set<T> x);
template<class T,class U>int sub(map<T,U>x);
template<class T>int sub(T x);

string padding(string x){return ("   " + x).substr(size(x));}
int sub(const string x){debug+=x+" ";return 0;}
//int sub(const string x){debug+=padding(x)+" ";return 0;}
int sub(const char* x){return sub((string)x);}
int sub(const bool x){return sub(x?"1":"0");}
#ifdef ATCODER
int sub(modint x){return sub(x.to_string());}
int sub(modint1000000007 x){return sub(x.to_string());}
int sub(modint998244353 x){return sub(x.to_string());}
#endif
int sub(bitset<10> x){return sub(x.to_string());}
template<class T,class U>int sub(pair<T,U>x){sub(x.first);sub(x.second);return 1;}
template<class T>int sub(tuple<T>x){sub(get<0>(x));return 0;}
template<class T,class U> int sub(tuple<T,U>x){sub(get<0>(x));sub(get<1>(x));return 1;}
template<class T,class U,class V>int sub(tuple<T,U,V>x){sub(get<0>(x));sub(get<1>(x));sub(get<2>(x));return 1;}
template<class T,class U,class V,class W>int sub(tuple<T,U,V,W> x){sub(get<0>(x));sub(get<1>(x));sub(get<2>(x));sub(get<3>(x));return 1;}
template<class T,class U,class V,class W, class X>int sub(tuple<T,U,V,W,X>x){sub(get<0>(x));sub(get<1>(x));sub(get<2>(x));sub(get<3>(x));sub(get<4>(x)); return 1;}
template<class T,class U,class V,class W, class X, class Y>int sub(tuple<T,U,V,W,X,Y>x){sub(get<0>(x));sub(get<1>(x));sub(get<2>(x));sub(get<3>(x));sub(get<4>(x));sub(get<5>(x)); return 1;}
template<class T,class U,class V,class W, class X, class Y, class Z>int sub(tuple<T,U,V,W,X,Y,Z>x){sub(get<0>(x));sub(get<1>(x));sub(get<2>(x));sub(get<3>(x));sub(get<4>(x));sub(get<5>(x));sub(get<6>(x));return 1;}
template<class T>int sub(queue<T>x){int result=1;while(!x.empty()){if(sub(x.front()))debug+="\n";result++;x.pop();}return result;}
template<class T>int sub(priority_queue<T>x){int result=1;while(!x.empty()){if(sub(x.top()))result++;x.pop();}return result;}
template<class T>int sub(priority_queue<T,vector<T>,greater<T>>x){int result=1;while(!x.empty()){if(sub(x.top()))result++;x.pop();}return result;}
template<class T>int sub(vector<T>x){int result=1;for(int i=0;i<min<int>(CNT,size(x));++i){if(sub(x.at(i))){debug+="\n";result++;}}return result;}
template<class T>int sub(set<T> x){int result=1;for(const auto&e:x){if(sub(e)){debug+="\n";result++;}}return result;}
template<class T>int sub(set<T,greater<T>> x){int result=1;for(const auto&e:x){if(sub(e)){debug+="\n";result++;}}return result;}
template<class T>int sub(multiset<T> x){int result=1;for(const auto&e:x){if(sub(e)){debug+="\n";result++;}}return result;}
template<class T>int sub(multiset<T,greater<T>> x){int result=1;for(const auto&e:x){if(sub(e)){debug+="\n";result++;}}return result;}
template<class T,class U>int sub(map<T,U>x){debug+="\n";for(const auto&[e,f]:x){sub(e);sub(f);debug+="\n";}return 1;}
template<class T>int sub(T x){return sub(x>1e9?"inf":(x<-1e9?"-inf":to_string(x)));}
#endif
