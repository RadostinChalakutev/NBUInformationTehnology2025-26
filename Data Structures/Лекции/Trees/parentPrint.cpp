
void parenPrint(const Tree& T, const Position& v) {
    cout << v.element();					// print node's element
    if (T.isInternal(v)) {
        PositionIterator children = T.children(v);
        cout << "( ";					// open
        parenPrint(T, children.next());			// visit the first child
        while (children.hasNext()) {			// for each other child
            cout << ", ";					// print separator
            parenPrint(T, children.next());			// visit the next child
        }
        cout << " )";					// close
    }
}