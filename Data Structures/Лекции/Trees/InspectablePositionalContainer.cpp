
template <typename Object>
class InspectablePositionalContainer
  : public InspectableContainer<Object> {
public:
    class Position;					// node position type
    class PositionIterator;				// position iterator
    PositionIterator positions() const;			// get position iterator
};