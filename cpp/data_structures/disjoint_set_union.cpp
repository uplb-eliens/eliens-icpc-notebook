struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) make_set(i);
  }
  void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
  }
  bool is_same(int a, int b) { return find_set(a) == find_set(b); }
  int find_set(int v) { return v == parent[v] ? v : parent[v] = find_set(parent[v]); }
  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};