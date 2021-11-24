template <class T>
struct segtree {

	int n, size;
	vector<T> tree;
	T dummy_value;
	T(*merge) (T left_node, T right_node);

	void init(int _n, T _dummy_value, T(*_merge) (T, T)) {
		n = _n;
		int x = ceil(log2(n));
		size = (1 << (x + 1)) + 1;
		tree.resize(size + 1);
		dummy_value = _dummy_value;
		merge = _merge;
	}

	void pointUpdate(int index, T new_value, int lx, int rx, int ix) {
		if (index < lx || index > rx) return;
		if (lx == rx) {
			tree[ix] = new_value;
			return;
		}
		int mid = (lx + rx) >> 1;
		pointUpdate(index, new_value, lx, mid, (ix << 1) + 1);
		pointUpdate(index, new_value, mid + 1, rx, (ix << 1) + 2);
		tree[ix] = merge(tree[(ix << 1) + 1], tree[(ix << 1) + 2]);
	}

	void pointUpdate(int index, T new_value) {
		pointUpdate(index, new_value, 0, n - 1, 0);
	}

	T query(int l, int r, int lx, int rx, int ix) {
		if (r < lx || l > rx) {return dummy_value;}
		if (l <= lx && rx <= r) {return tree[ix];}
		int mid = (lx + rx) >> 1;
		T left_node_val = query(l, r, lx, mid, (ix << 1) + 1);
		T right_node_val = query(l, r, mid + 1, rx, (ix << 1) + 2);
		return merge(left_node_val, right_node_val);
	}

	T query(int l, int r) {
		return query(l, r, 0, n - 1, 0);
	}
};
