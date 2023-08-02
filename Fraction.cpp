class Fraction{
public:
    ll num = 0;
    ll den = 1;

    Fraction(){};
    Fraction(ll Num) : num(Num){};
    Fraction(ll Num, ll Den) : num(Num), den(Den){ reduction();};

    void reduction();
    Fraction operator +(Fraction y);
    Fraction operator -(Fraction y);
    Fraction operator -();
    Fraction operator *(Fraction y);
    Fraction operator /(Fraction y);
    void operator +=(Fraction y);
    void operator -=(Fraction y);
    void operator *=(Fraction y);
    void operator /=(Fraction y);
    bool operator ==(Fraction y) const;
    bool operator !=(Fraction y) const;
    bool operator <(Fraction y) const;
    bool operator >(Fraction y) const;
};
Fraction operator *(ll x, Fraction y);

void Fraction::reduction(){
    ll g = gcd(num, den);
    num /= g;
    den /= g;
    if(den < 0){
        num *= -1;
        den *= -1;
    }
}

Fraction Fraction::operator +(Fraction y){
    Fraction result(num * y.den + y.num * den, den * y.den);
    result.reduction();
    return result;
}

Fraction Fraction::operator -(Fraction y){
    return *this + (-y);
}

Fraction Fraction::operator -(){
    return *this * (-1);
}

Fraction Fraction::operator *(Fraction y){
    Fraction result(num * y.num, den * y.den);
    result.reduction();
    return result;
}

Fraction operator *(ll x, Fraction y){
    return Fraction(x) * y;
}

Fraction Fraction::operator /(Fraction y){
    Fraction result(num * y.den, den * y.num);
    result.reduction();
    return result;
}

void Fraction::operator +=(Fraction y){
    *this = *this + y;
}

void Fraction::operator -=(Fraction y){
    *this = *this - y;
}

void Fraction::operator *=(Fraction y){
    *this = *this * y;
}

void Fraction::operator /=(Fraction y){
    *this = *this / y;
}

bool Fraction::operator ==(Fraction y) const{
    return num * y.den == den * y.num;
}

bool Fraction::operator !=(Fraction y) const{
    return !(*this == y);
}

bool Fraction::operator <(Fraction y) const{
    return num * y.den < den * y.num;
}

bool Fraction::operator >(Fraction y) const{
    return num * y.den > den * y.num;
}

ostream& operator <<(ostream& os, Fraction x){
    os << to_string(x.num) << "/" << to_string(x.den);
    return os;
}
