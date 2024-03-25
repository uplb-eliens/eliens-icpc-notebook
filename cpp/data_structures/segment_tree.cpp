template<typename T, typename InType = T>
class SegTreeNode {
public:
  const T IDN = 0, DEF = 0;
  int i, j;
  T val;
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
    val = op(lc->val, rc->val);
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
    if (j <= l || r <= i) return IDN;
    return op(lc->range_query(l, r), rc->range_query(l, r));
  }
  T op(T x, T y) {}
};
template<typename T, typename InType = T>
class SegTree {
public:
  SegTreeNode<T, InType> root;
  SegTree(int n) : root(0, n) {}
  SegTree(const vector<InType>& a) : root(a, 0, a.size()) {}
  void set(int k, T x) { root.set(k, x); }
  T range_query(int l, int r) { return root.range_query(l, r); }
};