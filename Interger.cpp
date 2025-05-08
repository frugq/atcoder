//整数範囲の計算ライブラリ
class Interger{
public:
    bigint val;
    
    Interger(){}
    Interger(ll Val){
        val = Val;
    }
    Interger(bigint Val){
        val = Val;
    }

    bool operator<(const Interger& y) const{
        return val < y.val;
    }
    
    bool operator<=(const Interger& y) const{
        return val <= y.val;
    }

    bool operator>(const Interger& y) const{
        return val > y.val;
    }

    bool operator>=(const Interger& y) const{
        return val >= y.val;
    }

    bool operator==(const Interger& y) const{
        return val == y.val;
    }

    bool operator!=(const Interger& y) const{
        return !(*this == y.val);
    }
    
    Interger operator +(const Interger& y) const{
        return Interger(val + y.val);
    }

    Interger operator -(const Interger& y) const{
        return Interger(val - y.val);
    }
    
    Interger operator *(const Interger& y) const{
        return Interger(val * y.val);
    }

    Interger operator /(const Interger& y) const{
        return Interger(val / y.val);
    }

    void operator +=(const Interger& y){
        val += y.val;
    }
    
    void operator -=(const Interger& y){
        val -= y.val;
    }
    
    void operator *=(const Interger& y){
        val *= y.val;
    }
    
    void operator /=(const Interger& y){
        val /= y.val;
    }

    Interger pow(const Interger& y) const{
        bigint result = 1;
        rep(i, y.val){
            result *= val;
        }
        return result;
    }

    Interger sqrt(const Interger& n = 2) const{//floor(√x) 範囲注意
        Interger l = bigint(-1), r = bigint(2 * std::pow((double)(val), 1.0 / (double)(n.val)) + 10);
        while(r - l > Interger(1)){
            Interger m = (l + r) / Interger(2);
            if(m.pow(n) <= *this){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }

    Interger log(const Interger& base) const{//log_base(x)
        Interger l = bigint(-1), r = bigint(2 * std::log((double)(base.val)) /  std::log((double)(val)) + 10);
        while(r - l > 1){
            Interger m = (l + r) / 2;
            if(base.pow(m) <= *this){
                l = m;
            }else{
                r = m;
            }
        }
        return l;
    }

    #ifdef __LOCAL
    friend int push(const Interger& y){
        debug::push(y.val);
        return 1;
    }
    #endif
};
