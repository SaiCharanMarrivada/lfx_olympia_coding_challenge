#include <vector>
// virtual class, all other classes inherit from this class
class Object {
public:
    virtual void describe() = 0;
    virtual float area() = 0;
    virtual void parse(const std::vector<float> &args) = 0;
    virtual float perimeter() = 0;
};
