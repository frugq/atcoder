template<class T>
class Vec{
public:
    T x, y, z;

    Vec(T X, T Y) : x(X), y(Y), z(0){}
    Vec(T X, T Y, T Z) : x(X), y(Y), z(Z){}

    Vec operator +(Vec b){
        return Vec(x + b.x, y + b.y, z + b.z);
    }

    Vec operator -(){
        return Vec(-x, -y, -z);
    }

    Vec operator -(Vec b){
        return *this + (-b);
    }

    void operator +=(Vec b){
        x += b.x;
        y += b.y;
        z += b.z;
    }

    void operator -=(Vec b){
        *this += (-b);
    }

    Vec operator *(T b){
        return Vec(b * x, b * y, b * z);
    }

    void operator *=(T b){
        x *= b;
        y *= b;
        z *= b;
    }

    Vec operator /(T b){
        return Vec(x / b, y / b, z / b);
    }

    void operator /=(T b){
        x /= b;
        y /= b;
        z /= b;
    }

    T dot(Vec a, Vec b){
        return a.x * b.x + a.y + b.y + a.z + b.z;
    }

    Vec cross(Vec a, Vec b){
        return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }

    friend Vec operator *(T b, Vec a){
        return a * b;
    }

    friend ostream& operator <<(ostream& os, Vec vec){
        os << vec.x << " " << vec.y << " " << vec.z;
        return os;
    }
};
