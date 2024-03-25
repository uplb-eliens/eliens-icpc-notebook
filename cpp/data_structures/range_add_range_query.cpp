template<typename T, typename InType = T>
class SegTreeNode {
public:
  const T IDN = 0, DEF = 0;
  int i, j;
  T val, to_add = 0;
  SegTreeNode<T, InType>* lc, * rc;
  SegTreeNode(int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      lc = rc = nullptr;
      val = DEF;
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode<T, InType>(i, k);
    rc = new SegTreeNode<T, InType>(k, j);
    val = operation(lc->val, rc->val);
  }
  SegTreeNode(const vector<InType>& a, int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      lc = rc = nullptr;
      val = a[i];
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode<T, InType>(a, i, k);
    rc = new SegTreeNode<T, InType>(a, k, j);
    val = operation(lc->val, rc->val);
  }
  void propagate() {
    if (to_add == 0) return;
    val += to_add;
    if (j - i > 1) {
      lc->to_add += to_add;
      rc->to_add += to_add;
    }
    to_add = 0;
  }
  void range_add(int l, int r, T delta) {
    propagate();
    if (r <= i || j <= l) return;
    if (l <= i && j <= r) {
      to_add += delta;
      propagate();
    } else {
      lc->range_add(l, r, delta);
      rc->range_add(l, r, delta);
      val = operation(lc->val, rc->val);
    }
  }
  T range_query(int l, int r) { // [l, r)
    propagate();
    if (l <= i && j <= r) return val;
    if (j <= l || r <= i) return IDN;
    return operation(lc->range_query(l, r), rc->range_query(l, r));
  }
  T operation(T x, T y) {}
};

template<typename T, typename InType = T>
class SegTree {
public:
    SegTreeNode<T, InType> root;
    SegTree(int n) : root(0, n) {}
    SegTree(const vector<InType>& a) : root(a, 0, a.size()) {}
    void range_add(int l, int r, T delta) { root.range_add(l, r, delta); }
    T range_query(int l, int r) { return root.range_query(l, r); }
};