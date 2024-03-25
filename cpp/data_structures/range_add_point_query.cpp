template<class T>
class SegTreeNode {
public:
  const T IDENTITY = 0;
  int i, j;
  T value;
  SegTreeNode<T>* lc, * rc;
  SegTreeNode(int i, int j) : i(i), j(j) {
    value = IDENTITY;
    if (j - i == 1) {
      lc = rc = nullptr;
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode(i, k);
    rc = new SegTreeNode(k, j);
  }
  SegTreeNode(const vector<T>& a, int i, int j) : i(i), j(j) {
    value = j - i == 1 ? a[i] : IDENTITY;
    if (j - i == 1) {
      lc = rc = nullptr;
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode(a, i, k);
    rc = new SegTreeNode(a, k, j);
  }
  void range_update(int l, int r, T x) {
    if (r <= i || j <= l) return;
    if (l <= i && j <= r) {
      value = op(value, x);
      return;
    }
    lc->range_update(l, r, x);
    rc->range_update(l, r, x);
  }
  T point_query(int k) {
    if (k < i || j <= k) return IDENTITY;
    if (j - i == 1) {
      return value;
    }
    return op(value, op(lc->point_query(k), rc->point_query(k)));
  }
  T op(T x, T y) { return x + y; }
};
template<class T>
class SegTree {
public:
  SegTreeNode<T> root;
  SegTree(int n) : root(0, n) {}
  SegTree(const vector<T>& a) : root(a, 0, a.size()) {}
  void range_update(int l, int r, T x) { root.range_update(l, r, x); }
  T point_query(int k) { return root.point_query(k); }
};