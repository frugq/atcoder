//整数範囲の計算ライブラリ
class Interger{
public:
    bigint val;
    
    Interger(){}
    Interger(ll Val){
        val = bigint(Val);
    }
    Interger(bigint Val){
        val = Val;
    }
    Interger(string Val){
        val = bigint(Val);
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
        if(val == 0) return Interger(1);
        if(val == 1) return Interger(1);
        bigint result = 1, yy = y.val, tmp = val;
        while(yy){
            if(yy & 1){
                result *= tmp;
            }
            yy >>= 1;
            tmp *= tmp;
        }
        return Interger(result);
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
