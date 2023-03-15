ll get_minimum(stack<pair<ll, ll>> &s1, stack<pair<ll, ll>> &s2) {
  if (s1.empty() || s2.empty()) {
    return s1.empty() ? s2.top().second : s1.top().second;
  } else {
    return min(s1.top().second, s2.top().second);
  }
}
void add_element(ll new_element, stack<pair<ll, ll>> &s1) {
  ll minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
  s1.push({new_element, minimum});
}
ll remove_element(stack<pair<ll, ll>> &s1, stack<pair<ll, ll>> &s2) {
  if (s2.empty()) {
    while (!s1.empty()) {
      ll element = s1.top().first;
      s1.pop();
      ll minimum = s2.empty() ? element : min(element, s2.top().second);
      s2.push({element, minimum});
    }
  }
  ll removed_element = s2.top().first;
  s2.pop();
  return removed_element;
}