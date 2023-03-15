class UF {
private: vector<ll> p;
public:
  UF(ll N) {p.assign(N, -1);}
  ll fs(ll i ) {
    return (p[i] < 0) ? i : (p[i] = fs(p[i]));
  }
  bool isSame(ll i, ll j) {
    return fs(i) == fs(j);
  }
  void join(ll i, ll j) {
    ll x = fs(i), y = fs(j);
    if (x != y){    
      if (x < y) { 
        p[x] += p[y]; 
        p[y] = x; 
      }
      else {
        p[y] += p[x]; p[x] = y; 
      } 
    } 
  }
};