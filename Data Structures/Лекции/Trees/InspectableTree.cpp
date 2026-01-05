
template <typename Object>
class InspectableTree
  : public InspectablePositionalContainer<Object> {
public:
    Position root() const;				// get root of tree
    Position parent(const Position& v) const;		// get parent of v
    PositionIterator children(const Position& v) const;	// iterator for children
    bool isInternal(const Position& v) const;		// internal node?
    bool isExternal(const Position& v) const;		// external node?
    bool isRoot(const Position& v) const;			// the root?
};