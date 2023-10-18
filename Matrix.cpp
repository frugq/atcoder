template<class T>
class Mat{
public:
  using V2 = vector<vector<T>>;
  int h, w;
  V2 elem;
  
  Mat(){}
  Mat(int H, int W);
  Mat(const V2& Vec);
  Mat unit(int n);
  Mat operator+(const Mat<T>& y);
  void operator+=(const Mat<T>& y);
  Mat operator -(const Mat<T>& y);
  Mat operator -();
  void operator -=(const Mat<T>& y);
  Mat operator *(const Mat<T>& y);
  void operator *=(const Mat<T>& y);
  Mat operator *(T y);
  void operator *=(T y);
  Mat operator /(T y);
  void operator /=(T y);
  Mat pow(ll y);
  Mat trans();
  Mat inv();
  bool operator ==(const Mat<T>& y) const;
  bool operator !=(const Mat<T>& y) const;
};
template<class T> Mat<T> operator -(const Mat<T>& y);
template<class T> Mat<T> operator *(T x, const Mat<T>& y);
template<class T> ostream& operator<<(ostream& os, const Mat<T>& y);

template<class T>
Mat<T>::Mat(int H, int W){
  h = H;
  w = W;
  elem.resize(h, vector<T>(w, 0));
}

template<class T>
Mat<T>::Mat(const V2& Vec){
  h = size(Vec);
  assert(h > 0);
  w = size(Vec.at(0));
  assert(w > 0);
  elem = Vec;
}

template<class T>
Mat<T> Mat<T>::unit(int n){
  Mat<T> result(n, n);
  for(int i = 0; i < n; ++i){
    result.elem.at(i).at(i) = 1;
  }
  return result;
}

template<class T>
Mat<T> Mat<T>::operator +(const Mat<T>& y){
  assert(h == y.h);
  assert(w == y.w);
  Mat<T> result = *this;
  result += y;
  return result;
}

template<class T>
void Mat<T>::operator +=(const Mat<T>& y){
  assert(h == y.h);
  assert(w == y.w);
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      elem.at(i).at(j) += y.elem.at(i).at(j);
    }
  }
}

template<class T>
Mat<T> Mat<T>::operator -(const Mat<T>& y){
  assert(h == y.h);
  assert(w == y.w);
  return *this + (-y);
}

template<class T>
Mat<T> operator -(const Mat<T>& y){
  return (Mat<T>)y * (-1);
}

template<class T>
void Mat<T>::operator -=(const Mat<T>& y){
  assert(h == y.h);
  assert(w == y.w);
  *this = *this - y;
}

template<class T>
Mat<T> Mat<T>::operator *(const Mat<T>& y){
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

template<class T>
Mat<T> Mat<T>::operator *(T y){
  Mat<T> result = *this;
  result *= y;
  return result;
}

template<class T>
Mat<T> operator *(T x, const Mat<T>& y){
  return (Mat<T>)y * x;
}

template<class T>
void Mat<T>::operator *=(const Mat<T>& y){
  assert(w == y.h);
  *this = *this * y;
}

template<class T>
void Mat<T>::operator *=(T y){
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      elem.at(i).at(j) *= y;
    }
  }
}

template<class T>
Mat<T> Mat<T>::operator /(T y){
  Mat<T> result = *this;
  result /= y;
  return result;
}

template<class T>
void Mat<T>::operator /=(T y){
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      elem.at(i).at(j) *= y;
    }
  }
}

template<class T>
Mat<T> Mat<T>::pow(ll y){
  assert(y >= 0);
  assert(h == w);
  Mat<T> result = Mat<T>::unit(h);
  Mat<T> tmp = *this;
  while(y){
    if(y & 1){
      result *= tmp;
    }
    tmp *= tmp;
    y >>= 1LL;
  }
  return result;
}

template<class T>
Mat<T> Mat<T>::trans(){
  Mat<T> result(w, h);
  for(int i = 0; i < w; ++i){
    for(int j = 0; j < w; ++j){
      result.at(i).at(j) = elem.at(j).at(i);
    }
  }
  return result;
}

template<class T>
Mat<T> Mat<T>::inv(){
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

template<class T>
bool Mat<T>::operator ==(const Mat& y) const{
  if(h != y.h) return false;
  if(w != y.w) return false;
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(elem.at(i).at(j) != y.elem.at(i).at(j)) return false;
    }
  }
  return true;
}

template<class T>
bool Mat<T>::operator !=(const Mat& y) const{
  return !(*this == y);
}
