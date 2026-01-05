
void preorderPrint(const Tree& T, const Position& v) {
    cout << v.element();					// print element
    PositionIterator children = T.children(v);		// visit children
    while (children.hasNext()) {
        cout << " ";
        preorderPrint(T, children.next());
    }
}