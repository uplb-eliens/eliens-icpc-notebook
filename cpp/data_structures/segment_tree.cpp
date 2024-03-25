template<class T>
class SegTreeNode {
public:
  const T IDENTITY = 0, DEFAULT = 0;
  int i, j;
  T val;
  SegTreeNode<T>* lc, * rc;
  SegTreeNode(int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      lc = rc = nullptr;
      val = DEFAULT;
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode(i, k);
    rc = new SegTreeNode(k, j);
    val = op(lc->val, rc->val);
  }
  SegTreeNode(const vector<T>& a, int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      lc = rc = nullptr;
      val = a[i];
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTreeNode(a, i, k);
    rc = new SegTreeNode(a, k, j);
    val = op(lc->val, rc->val);
  }
  void set(int k, T x) { // update a[k] := x
    if (k < i || j <= k) return;
    if (j - i == 1) {
        val = x;
        return;
    }
    lc->set(k, x);
    rc->set(k, x);
    val = op(lc->val, rc->val);
  }
  T range_query(int l, int r) { // [l, r)
    if (l <= i && j <= r) return val;
    if (j <= l || r <= i) return IDENTITY;
    return op(lc->range_query(l, r), rc->range_query(l, r));
  }
  T op(T x, T y) {}
};
template<class T>
class SegTree {
public:
  SegTreeNode<T> root;
  SegTree(int n) : root(0, n) {}
  SegTree(const vector<T>& a) : root(a, 0, a.size()) {}
  void set(int k, T x) { root.set(k, x); }
  T range_query(int l, int r) { return root.range_query(l, r); }
};