class MultiMod{
public:
    using mint0 = static_modint<1000000007>;
    using mint1 = static_modint<1000000009>;
    using mint2 = static_modint<1000000021>;
    using mint3 = static_modint<1000000033>;
    mint0 val0;
    mint1 val1;
    mint2 val2;
    mint3 val3;

    MultiMod(ll val){
        val0 = val;
        val1 = val;
        val2 = val;
        val3 = val;
    }

    MultiMod(){
        val0 = 0;
        val1 = 0;
        val2 = 0;
        val3 = 0;
    }

    MultiMod operator +=(MultiMod x){
        val0 += x.val0;
        val1 += x.val1;
        val2 += x.val2;
        val3 += x.val3;
        return *this;
    }

    MultiMod operator +(MultiMod x) const{
        MultiMod m = *this;
        m += x;
        return m;
    }

    MultiMod operator *=(MultiMod x){
        val0 *= x.val0;
        val1 *= x.val1;
        val2 *= x.val2;
        val3 *= x.val3;
        return *this;
    }
    MultiMod operator *(MultiMod x) const{
        MultiMod m = *this;
        m *= x;
        return m;
    }

    MultiMod operator -() const{
        MultiMod m = *this;
        m *= -1;
        return m;
    }

    MultiMod operator -=(MultiMod x){
        val0 -= x.val0;
        val1 -= x.val1;
        val2 -= x.val2;
        val3 -= x.val3;
        return *this;
    }

    MultiMod operator -(MultiMod x) const{
        MultiMod m = *this;
        m += (-x);
        return m;
    }

    MultiMod operator /=(MultiMod x){
        val0 /= x.val0;
        val1 /= x.val1;
        val2 /= x.val2;
        val3 /= x.val3;
        return *this;
    }
    MultiMod operator /(MultiMod x) const{
        MultiMod m = *this;
        m /= x;
        return m;
    }

    MultiMod pow(ll n){
        MultiMod m;
        m.val0 = val0.pow(n);
        m.val1 = val1.pow(n);
        m.val2 = val2.pow(n);
        m.val3 = val3.pow(n);
        return m;
    }

    bool operator ==(MultiMod x) const{
        return (val0 == x.val0) && (val1 == x.val1) && (val2 == x.val2) && (val3 == x.val3);
    }

    #ifdef __LOCAL
    friend int push(MultiMod m){
        debug::push("[");
        debug::push(m.val0.val());
        debug::push(m.val1.val());
        debug::push(m.val2.val());
        debug::push(m.val3.val());
        debug::push("]");
        return 1;
    }
    #endif
};
