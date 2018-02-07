// SEGMENT TREE

typedef long long ll;

struct node
{
    ll val;

    void init(ll v)
    {
        val = v;
    }

    void identity()
    {
        val = 0;
    }

    void split(node &a, node &b)
    {

    }
    void merge(node &a, node &b)
    {

    }

};

node Tree[1000006];         // 1-base SEG-TREE array
ll A[100005];           // INPUT ARRAY

void buildTree(ll si, ll ss, ll se)
{
    if(ss==se)
    {
        Tree[si].init(A[ss]);
        return;
    }
    ll sm = ss+(se-ss)/2;
    ll lc = 2*si;
    ll rc = lc+1;
    buildTree(lc, ss, sm);
    buildTree(rc, sm+1, se);
    Tree[si].merge(Tree[lc], Tree[rc]);
}

node range_query(ll si, ll ss, ll se, ll qs, ll qe)
{
    if(ss>=qs && se<=qe)
    {
        return Tree[si];
    }
    ll sm = ss+(se-ss)/2;
    ll lc = 2*si;
    ll rc = lc+1;
    Tree[si].split(Tree[lc], Tree[rc]);
    node l, r;
    l.identity();
    r.identity();
    if(qs<=sm) l = range_query(lc, ss, sm, qs, qe);
    if(qs>sm) r = range_query(rc, sm+1, se, qs, qe);
    Tree[si].merge(Tree[lc], Tree[rc]);
    node res;
    res.merge(l, r);
    return res;
}

void update_single_node(node &n, ll new_val)
{
    n.init(new_val);
}

void range_update(ll si, ll ss, ll se, ll qs, ll qe, ll new_val)
{
    if(ss>=qs && se<=qe)
    {
        update_single_node(Tree[si], new_val);
        return;
    }
    ll sm = ss+(se-ss)/2;
    ll lc = 2*si;
    ll rc = lc+1;
    Tree[si].split(Tree[lc], Tree[rc]);
    if(qs<=sm) range_update(lc, ss, sm, qs, qe, new_val);
    if(qe>sm) range_update(rc, sm+1, se, qs, qe, new_val);
    Tree[si].merge(Tree[lc], Tree[rc]);
}

void update(ll si, ll ss, ll se, ll qi , ll val)
{
    range_update(si, ss, se, qi, qi, val);
}
