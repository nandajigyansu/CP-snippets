template <class T> class SegTree
{
public:
	// SegTree constructors
	SegTree(T *ar, int n, T DEFAULT_VALUE, T (*merge) (T LEFT_NODE, T RIGHT_NODE));
	// range query from L to R (0-based indexing)
	T query(int L, int R);
	// point update (0-based indexing)
	void pointUpdate(int INDEX, T NEW_VALUE);

private:
	// N = size of Array, size = size of Segment Tree Array
	int N, size;
	// Segment Tree array
	vector<T> tree;
	// Identity Value
	T DUMMY_VALUE;
	// merge left node and right node of Segment Tree
	T (*merge) (T LEFT_NODE, T RIGHT_NODE);
	// build Segment Tree
	void buildTree(T *ar, int SS, int SE, int IDX);
	// answer range query (recursive)
	T queryRec(int L, int R, int SS, int SE, int IDX);
	// point update (recursive)
	void pointUpdateRec(int INDEX, T NEW_VALUE, int SS, int SE, int IDX);
};

template <class T> SegTree<T>::SegTree(T *ar, int n, T DEFAULT_VALUE, T (*merge) (T LEFT_NODE, T RIGHT_NODE))
{
	this->merge = merge;
	DUMMY_VALUE = DEFAULT_VALUE;
	N = n;
	int x = ceil(log2(N));
	size = (1 << (x + 1)) + 1;
	tree.resize(size + 1);
	buildTree(ar, 0, N - 1, 0);
}

template <class T> void SegTree<T>::buildTree(T *ar, int SS, int SE, int IDX)
{
	if (SS == SE) {
		tree[IDX] = ar[SS];
		return;
	}
	int mid = (SS + SE) >> 1;
	buildTree(ar, SS, mid, (IDX << 1) + 1);
	buildTree(ar, mid + 1, SE, (IDX << 1) + 2);
	tree[IDX] = merge(tree[(IDX << 1) + 1], tree[(IDX << 1) + 2]);
	return;
}

template <class T> T SegTree<T>::query(int L, int R)
{
	return queryRec(L, R, 0, N - 1, 0);
}

template <class T> T SegTree<T>::queryRec(int L, int R, int SS, int SE, int IDX)
{
	if (R < SS || L > SE) {return DUMMY_VALUE;}
	if (L <= SS && SE <= R) {return tree[IDX];}
	int mid = (SS + SE) >> 1;
	T LEFT_NODE_VAL = queryRec(L, R, SS, mid, (IDX << 1) + 1);
	T RIGHT_NODE_VAL = queryRec(L, R, mid + 1, SE, (IDX << 1) + 2);
	return merge(LEFT_NODE_VAL, RIGHT_NODE_VAL);
}

template <class T> void SegTree<T>::pointUpdate(int INDEX, T NEW_VALUE)
{
	pointUpdateRec(INDEX, NEW_VALUE, 0, N - 1, 0);
}

template <class T> void SegTree<T>::pointUpdateRec(int INDEX, T NEW_VALUE, int SS, int SE, int IDX)
{
	if (INDEX < SS || INDEX > SE) {return;}
	if (SS == SE) {
		tree[IDX] = NEW_VALUE;
		return;
	}
	if (SE > SS) {
		int mid = (SS + SE) >> 1;
		pointUpdateRec(INDEX, NEW_VALUE, SS, mid, (IDX << 1) + 1);
		pointUpdateRec(INDEX, NEW_VALUE, mid + 1, SE, (IDX << 1) + 2);
		tree[IDX] = merge(tree[(IDX << 1) + 1], tree[(IDX << 1) + 2]);
		return;
	}
}
