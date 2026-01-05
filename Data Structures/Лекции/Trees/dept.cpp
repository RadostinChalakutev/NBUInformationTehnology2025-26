
int depth(const Tree& T, const Position& v) {
    if (T.isRoot(v))
        return 0;						// root has depth 0
    else
        return 1 + depth(T, T.parent(v));			// 1 + (depth of parent)
}