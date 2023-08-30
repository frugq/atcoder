#ifndef INIT_H
#define INIT_H
#include <bits/stdc++.h>
using namespace std;

#define show(...)   debug::name = debug::separate(#__VA_ARGS__); \
                    debug::idx = 0; \
                    debug::show_sub(__VA_ARGS__); \
                    cerr << endl;
#ifdef DFUNC
#define dfunc(x)    cerr << __func__ << " " << #x << endl;
#endif
#ifndef DFUNC
#define dfunc(x)
#endif
namespace debug{
    using ll = long long;
    #define SIZE(x) (int)(x.size())
    vector<string> name;
    stringstream output;
    int idx = 0;
    int maxDispCnt = 100;
    string space = "                                                         ";

    int push(ll x);
    int push(double x);
    int push(int x);
    int push(char x);
    int push(string x);
    template<class T1, class T2> int push(pair<T1, T2> x);
    template<class T1> int push(tuple<T1> x);
    template<class T1, class T2> int push(tuple<T1, T2> x);
    template<class T1, class T2, class T3> int push(tuple<T1, T2, T3> x);
    template<class T1, class T2, class T3, class T4> int push(tuple<T1, T2, T3, T4> x);
    template<class T1, class T2, class T3, class T4, class T5> int push(tuple<T1, T2, T3, T4, T5> x);
    template<class T> int push(vector<T> x);
    template<class T> int push(set<T> x);
    template<class T> int push(set<T, greater<T>> x);
    template<class T> int push(multiset<T> x);
    template<class T> int push(multiset<T, greater<T>> x);
    template<class T> int push(queue<T> x);
    template<class T> int push(deque<T> x);
    template<class T> int push(priority_queue<T> x);
    template<class T> int push(priority_queue<T, vector<T>, greater<T>> x);
    template<class T1, class T2> int push(map<T1, T2> x);
    template<class T> int push(T x);

    vector<string> separate(string s){
        int cntOpen = 0;
        vector<string> result(1);
        for(const auto& e : s){
            if(e == '(') cntOpen++;
            if(e == ')') cntOpen--;
            if(e == ' ') continue;
            else if(e == ',' && cntOpen == 0) result.push_back("");
            else result.back() += e;
        }
        return result;
    }

    vector<string> outputSeparate(string s){
        vector<string> result;
        for(int i = 0; i < SIZE(s); ++i){
            char e = s.at(i);
            if(e == '\n'){
                result.push_back("\n");
            }else if(e == ' '){
                result.push_back(" ");
            }else{
                result.back() += e;
            }
        }
        return result;
    }

    int push(ll x){
        ll inf = 1LL << 60;
        if(inf <= x){
            output << " inf";
        }else if(x <= -inf){
            output << " -inf";
        }else{
            output << " " << x;
        }
        return 0;
    }

    int push(double x){
        double inf = 1e18;
        if(inf <= x){
            output << " inf";
        }else if(x <= -inf){
            output << " -inf";
        }else{
            output << " " << x;
        }
        return 0;
    }

    int push(int x){
        int inf = 1 << 30;
        if(inf <= x){
            output << " inf";
        }else if(x <= -inf){
            output << " -inf";
        }else{
            output << " " << x;
        }
        return 0;
    }

    int push(char x){
        output << " " << x;
        return 0;
    }
    
    int push(string x){
        output << " " << x;
        return 1;
    }

    template<class T1, class T2>
    int push(pair<T1, T2> x){
        push(x.first);
        push(x.second);
        return 1;
    }

    template<class T1>
    int push(tuple<T1> x){
        push(get<0>(x));
        return 1;
    }
    
    template<class T1, class T2>
    int push(tuple<T1, T2> x){
        push(get<0>(x));
        push(get<1>(x));
        return 1;
    }

    template<class T1, class T2, class T3>
    int push(tuple<T1, T2, T3> x){
        push(get<0>(x));
        push(get<1>(x));
        push(get<2>(x));
        return 1;
    }

    template<class T1, class T2, class T3, class T4>
    int push(tuple<T1, T2, T3, T4> x){
        push(get<0>(x));
        push(get<1>(x));
        push(get<2>(x));
        push(get<3>(x));
        return 1;
    }

    template<class T1, class T2, class T3, class T4, class T5>
    int push(tuple<T1, T2, T3, T4, T5> x){
        push(get<0>(x));
        push(get<1>(x));
        push(get<2>(x));
        push(get<3>(x));
        push(get<4>(x));
        return 1;
    }

    template<class T>
    int push(vector<T> x){
        int sep = 1;
        for(int i = 0; i < min<int>(maxDispCnt, SIZE(x)); ++i){
            int tmp = push(x.at(i));
            sep += tmp;
            if(tmp) output << "\n";
        }
        return sep;
    }

    template<class T1, class T2>
    int push(map<T1, T2> x){
        output << "\n";
        for(const auto& e : x){
            push(e);
            output << "\n";
        }
        return true;
    }

    template<class T>
    int push(T x){
        output << " " << x;
        return 0;
    }

    template<class T>
    int push(set<T> x){
        int sep = 1, cnt = 0;
        for(const auto& e : x){
            int tmp = push(e);
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(set<T, greater<T>> x){
        int sep = 1, cnt = 0;
        for(const auto& e : x){
            int tmp = push(e);
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(multiset<T> x){
        int sep = 1, cnt = 0;
        for(const auto& e : x){
            int tmp = push(e);
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(multiset<T, greater<T>> x){
        int sep = 1, cnt = 0;
        for(const auto& e : x){
            int tmp = push(e);
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(queue<T> x){
        int sep = 1, cnt = 0;
        while(!x.empty()){
            int tmp = push(x.front());
            x.pop();
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(deque<T> x){
        int sep = 1, cnt = 0;
        while(!x.empty()){
            int tmp = push(x.front());
            x.pop_front();
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(priority_queue<T> x){
        int sep = 1, cnt = 0;
        while(!x.empty()){
            int tmp = push(x.top());
            x.pop();
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    template<class T>
    int push(priority_queue<T, vector<T>, greater<T>> x){
        int sep = 1, cnt = 0;
        while(!x.empty()){
            int tmp = push(x.top());
            x.pop();
            if(tmp >= 1) output << "\n";
            sep += tmp;
            if(cnt++ >= maxDispCnt) break;
        }
        return sep;
    }

    void show_sub2(char x){
        if(idx != 0) cerr << ", ";
        cerr << x;
        idx++;
    }
    
    void show_sub2(const char* x){
        if(idx != 0) cerr << ", ";
        cerr << x;
        idx++;
    }

    template<class T>
    void show_sub2(T x){
        if(idx != 0) cerr << ", ";
        if(isdigit(name.at(idx).at(0))){
            cerr << name.at(idx);
        }else{
            if(push(x) >= 2){
                cerr << "\n" << name.at(idx) << " =\n";
            }else{
                cerr << name.at(idx) + " =";
            }

            int width = 0;
            bool sep = false;
            for(const auto& e : outputSeparate(output.str())){
                width = max(width, SIZE(e));
                if(e.back() == '\n') sep = true;
            }
            for(const auto& e : outputSeparate(output.str())){
                if(sep){
                    cerr << space.substr(0, width - size(e)) << e;
                }else{
                    cerr << e;
                }
            }
        }
        idx++;
    }

    //https://marycore.jp/prog/cpp/variadic-function/
    template<class T1>
    void show_sub(T1 first){
        output.str("");
        show_sub2(first);
    }

    template<class T1, class... T2>
    void show_sub(T1 first, T2... rest){
        output.str("");
        show_sub2(first);
        show_sub(rest...);
    }
}

#endif
