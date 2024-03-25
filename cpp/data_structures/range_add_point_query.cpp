template<typename T, typename InType = T>
class SegTreeNode {
public:
  const T IDN = 0, DEF = 0;
  int i, j;
  T val;
  SegTreeNode<T, InType>* lc, * rc;
  SegTreeNode(int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      val = DEF;
      lc = rc = nullptr;
      return;
    }
    val = 0;
    int k = (i + j) / 2;
    lc = new SegTreeNode<T, InType>(i, k);
    rc = new SegTreeNode<T, InType>(k, j);
  }
  SegTreeNode(const vector<InType>& a, int i, int j) : i(i), j(j) {
    if (j - i == 1) {
      val = (T) a[i];
      lc = rc = nullptr;
      return;
    }
    val = 0;
    int k = (i + j) / 2;
    lc = new SegTreeNode<T, InType>(a, i, k);
    rc = new SegTreeNode<T, InType>(a, k, j);
  }
  void range_add(int l, int r, T x) {
    if (r <= i || j <= l) return;
    if (l <= i && j <= r) {
      val += x;
      return;
    }
    lc->range_add(l, r, x);
    rc->range_add(l, r, x);
  }
  T point_query(int k) {
    if (k < i || j <= k) return IDN;
    if (j - i == 1) return val;
    return val + lc->point_query(k) + rc->point_query(k);
  }
};

template<typename T, typename InType = T>
class SegTree {
public:
  SegTreeNode<T, InType> root;
  SegTree(int n) : root(0, n) {}
  SegTree(const vector<InType>& a) : root(a, 0, a.size()) {}
  void range_add(int l, int r, T x) { root.range_add(l, r, x); }
  T point_query(int k) { return root.point_query(k); }
};