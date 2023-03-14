class UF {
private: vi p;
public:
    UF(int N) {p.assign(N, -1);}
    int fs(int i ) {return (p[i] < 0) ? i : (p[i] = fs(p[i]));}
    bool isSame(int i, int j) {return fs(i) == fs(j);}
    void join(int i, int j) {
        int x = fs(i), y = fs(j);
        if (!(x == y)){    
            if (x < y) { p[x] += p[y]; p[y] = x; }
            else {p[y] += p[x]; p[x] = y; } } }
};