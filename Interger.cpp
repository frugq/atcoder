//整数範囲の計算ライブラリ
template<class T>
class Interger{
public:
    T val;
    
    Interger(){}

    Interger(ll Val){
        val = T(Val);
    }
    Interger(T Val){
        val = Val;
    }

    bool operator<(const Interger<T>& y) const{
        return val < y.val;
    }
    
    bool operator<=(const Interger<T>& y) const{
        return val <= y.val;
    }

    bool operator>(const Interger<T>& y) const{
        return val > y.val;
    }

    bool operator>=(const Interger<T>& y) const{
        return val >= y.val;
    }

    bool operator==(const Interger<T>& y) const{
        return val == y.val;
    }

    bool operator!=(const Interger<T>& y) const{
        return !(*this == y.val);
    }
    
    Interger operator +(const Interger<T>& y) const{
        return Interger(val + y.val);
    }

    Interger operator -(const Interger<T>& y) const{
        return Interger(val - y.val);
    }
    
    Interger operator *(const Interger<T>& y) const{
        return Interger(val * y.val);
    }

    Interger operator /(const Interger<T>& y) const{
        return Interger(val / y.val);
    }

    void operator +=(const Interger<T>& y) const{
        val += y.val;
    }
    
    void operator -=(const Interger<T>& y) const{
        val -= y.val;
    }
    
    void operator *=(const Interger<T>& y) const{
        val *= y.val;
    }
    
    void operator /=(const Interger<T>& y) const{
        val /= y.val;
    }

    Interger pow(const Interger<T>& y) const{
        T result = 1;
        rep(i, y.val){
            result *= val;
        }
        return result;
    }

    Interger sqrt(const Interger<T>& n = 2, const Interger<T>& maxAns = Interger<T>(T(1 << 30))) const{//floor(√x) 範囲注意
        Interger<T> l = T(-1), r = maxAns;
        while(r - l > Interger<T>(1)){
            Interger<T> m = (l + r) / Interger<T>(2);
            if(m.pow(n) <= *this){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }

    Interger log(const Interger<T>& base, const Interger<T>& maxAns = Interger<T>(T(60))) const{//log_base(x)
        Interger<T> l = T(-1), r = maxAns;
        while(r - l > Interger<T>(1)){
            Interger<T> m = (l + r) / Interger<T>(2);
            show(m);
            if(base.pow(m) <= *this){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }

    #ifdef __LOCAL
    friend int push(const Interger<T>& y){
        debug::push(y.val);
        return 1;
    }
    #endif
};
