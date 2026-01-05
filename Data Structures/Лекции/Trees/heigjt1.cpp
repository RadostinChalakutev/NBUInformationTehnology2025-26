int height1(const Tree& T) {
    int h = 0;
    PositionIterator nodes = T.positions();
    while (nodes.hasNext())
    { Position v = nodes.next();
        if (T.isExternal(v)) h = max(h, depth(T, v));
    }
    return h;
}

