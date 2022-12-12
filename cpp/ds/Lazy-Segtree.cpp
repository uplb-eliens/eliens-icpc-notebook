int tree[MAX] = {0};  
int lazy[MAX] = {0};  
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) 
        { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>ue || se<us) 
        return ; 
    if (ss>=us && se<=ue) 
    { 
        tree[si] += (se-ss+1)*diff; 
        if (ss != se) 
        { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
void updateRange(int n, int us, int ue, int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) 
        { 
            // Since we are not yet updating children os si, 
            // we need to set lazy values for the children 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
  
        // unset the lazy value for current node as it has 
        // been updated 
        lazy[si] = 0; 
    } 
  
    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 
  
    // At this point we are sure that pending lazy updates 
    // are done for current node. So we can return value  
    // (same as it was for query in our previous post) 
  
    // If this segment lies in range 
    if (ss>=qs && se<=qe) 
        return tree[si]; 
  
    // If a part of this segment overlaps with the given 
    // range 
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 