
int height2(const Tree& T, const Position& v) {
    if (T.isExternal(v))
        return 0;						// leaf has height 0
    else {
        int h = 0;
        PositionIterator children = T.children(v);
        while (children.hasNext())
            h = max(h, height2(T, children.next()));
        return 1 + h;					// 1 + (max height)
    }
}