template <typename Object>
class PositionalContainer :
  public InspectablePositionalContainer<Object> {
public:
    void swapElements(const Position& v, const Position& w);
    Object& replaceElement(const Position& v, const Object& e);
};