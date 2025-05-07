//整数範囲の計算ライブラリ
template<class T>
class Interger{
public:
    T val;
    
    Interger(){}
    Interger(T Val){
        val = Val;
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

    
    Interger sqrt(const Interger<T>& y = 2) const{//範囲注意
        Interger<T> l = T(-1), r = T(1LL << 30);
        while(r - l > Interger<T>(1)){
            Interger<T> m = (l + r) / Interger<T>(2);
            if(m.pow(y) <= *this){
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
