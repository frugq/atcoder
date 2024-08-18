template<class T>
class Mat{
public:
    using V2 = vector<vector<T>>;
    int h, w;
    V2 elem;
  
    Mat(){}

    Mat(int H, int W){
        h = H;
        w = W;
        elem.resize(h, vector<T>(w, 0));
    }

    Mat(const V2& Vec){
        h = size(Vec);
        assert(h > 0);
        w = size(Vec.at(0));
        assert(w > 0);
        elem = Vec;
    }

    Mat unit(int n) const{
        Mat<T> result(n, n);
        for(int i = 0; i < n; ++i){
            result.elem.at(i).at(i) = 1;
        }
        return result;
    }

    void operator+=(const Mat<T>& y){
        assert(h == y.h);
        assert(w == y.w);
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
            elem.at(i).at(j) += y.elem.at(i).at(j);
            }
        }
    }

    Mat operator+(const Mat<T>& y) const{
        assert(h == y.h);
        assert(w == y.w);
        Mat<T> result = *this;
        result += y;
        return result;
    }

    Mat operator *(const Mat<T>& y) const{
        assert(w == y.h);
        Mat<T> result(h, y.w);
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < y.w; ++j){
                for(int k = 0; k < w; ++k){
                    result.elem.at(i).at(j) += elem.at(i).at(k) * y.elem.at(k).at(j);
                }
            }
        }
        return result;
    }

    void operator *=(const Mat<T>& y){        
        assert(w == y.h);
        *this = *this * y;
    }

    void operator *=(T y){
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
            elem.at(i).at(j) *= y;
            }
        }
    }

    Mat operator *(T y){
        Mat<T> result = *this;
        result *= y;
        return result;
    }

    friend Mat operator *(T x, const Mat<T>& y){
        return (Mat<T>)y * x;
    }

    Mat operator -(const Mat<T>& y) const{
        assert(h == y.h);
        assert(w == y.w);
        return *this + (-y);
    }

    friend Mat<T> operator -(const Mat<T>& y){
        return (Mat<T>)y * (-1);
    }

    void operator -=(const Mat<T>& y){
        assert(h == y.h);
        assert(w == y.w);
        *this = *this - y;
    }
    
    void operator /=(T y){
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
            elem.at(i).at(j) *= y;
            }
        }
    }

    Mat operator /(T y){
        Mat result = *this;
        result /= y;
        return result;
    }

    Mat operator /(Mat y){
        return (*this) * y.inv();
    }

    Mat pow(ll n){
        assert(h == w && n >= 0);
        Mat<T> result = Mat<T>::unit(h);
        Mat<T> tmp = *this;
        while(n){
            if(n & 1){
            result *= tmp;
            }
            tmp *= tmp;
            n >>= 1LL;
        }
        return result;
    }

    Mat trans(){
        Mat<T> result(w, h);
        for(int i = 0; i < w; ++i){
            for(int j = 0; j < w; ++j){
            result.at(i).at(j) = elem.at(j).at(i);
            }
        }
        return result;
    }

    Mat inv(){ 
        assert(h == w);
        Mat<T> original = elem, result = unit(h);
        for(int i = 0; i < h; ++i){
            T tmp = original.elem.at(i).at(i);
            if(tmp == 0){
                for(int j = i + 1; j < h; ++j){
                    tmp = original.elem.at(j).at(i);
                    if(tmp != 0){
                        swap(original.elem.at(i), original.elem.at(j));
                        swap(result.elem.at(i), result.elem.at(j));
                        break;
                    }
                }
            }
            assert(tmp != 0);
            for(int j = 0; j < w; ++j){
                original.elem.at(i).at(j) /= tmp;
                result.elem.at(i).at(j) /= tmp;
            }
            for(int j = 0; j < h; ++j){
                if(i == j) continue;
                T tmp2 = original.elem.at(j).at(i);
                for(int k = 0; k < w; ++k){
                    original.elem.at(j).at(k) -= tmp2 * original.elem.at(i).at(k);
                    result.elem.at(j).at(k) -= tmp2 * result.elem.at(i).at(k);
                }
            }
        }
        return result;
    }
/*
    pair<Mat, vector<T>> solveLSE(const vector<T>& y){//連立方程式 
        assert(h == w);
        Mat<T> resultM = elem;
        vector<T> resultY = y;
        for(int i = 0; i < h; ++i){
            T tmp = resultM.elem.at(i).at(i);
            if(tmp == 0){
                for(int j = i + 1; j < h; ++j){
                    tmp = resultM.elem.at(j).at(i);
                    if(tmp != 0){
                        swap(resultM.elem.at(i), resultM.elem.at(j));
                        swap(resultY.elem.at(i), resultY.elem.at(j));
                        break;
                    }
                }
            }

            //i行目の先頭を1にする
            assert(tmp != 0);
            for(int j = 0; j < w; ++j){
                resultM.elem.at(i).at(j) /= tmp;
            }
            resultY.at(i) /= tmp;

            //i+1行目以降の先頭を0にする
            for(int j = 0; j < h; ++j){
                if(i == j) continue;
                T tmp2 = resultM.elem.at(j).at(i);
                for(int k = 0; k < w; ++k){
                    resultM.elem.at(j).at(k) -= tmp2 * resultM.elem.at(i).at(k);
                }
                resultY.elem.at(j).at(k) -= tmp2 * resultY.elem.at(i).at(k);
            }
        }
        return make_pair(resultM, resultY);
    }
*/
    bool operator ==(const Mat<T>& y) const{
        if(h != y.h) return false;
        if(w != y.w) return false;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(elem.at(i).at(j) != y.elem.at(i).at(j)) return false;
            }
        }
        return true;
    }

    bool operator !=(const Mat<T>& y) const{
        return !(*this == y);
    }

    friend ostream& operator<<(ostream& os, const Mat<T>& y){
        for(int i = 0; i < y.h; ++i){
            for(int j = 0; j < y.w; ++j){
                os << y.elem.at(i).at(j) << " ";
            }
            os << endl;
        }
        return os;
    }

    #ifdef __LOCAL
    friend int push(Mat<T>& y){
        for(int i = 0; i < y.h; ++i){
            for(int j = 0; j < y.w; ++j){
                debug::push(y.elem.at(i).at(j));
            }
            debug::push("\n");
        }
        return 2;
    }
    #endif
};
