#include <iostream>
#include <numbers>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

class Object {
public:
    virtual void parse(const std::vector<float> &args) = 0;
    virtual void describe() = 0;
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual ~Object() = default;
};

class Registry {
public:
    Registry(const Registry &other) = delete;
    Registry(Registry &&other) = delete;
    Registry &operator=(const Registry &other) = delete;
    Registry &operator=(Registry &&other) = delete;
    static Registry &instance() {
        static Registry instance;
        return instance;
    }

    void register_object(const std::string &name, Object *object) {
        map.emplace(name, object);
    }

    Object *get(const std::string &name) {
        auto iterator = map.find(name);
        if (iterator != map.end()) {
            return iterator->second.get();
        }
        return nullptr;
    }
private:
    Registry() = default;
    std::unordered_map<std::string, std::unique_ptr<Object>> map;
};

#define REGISTER(name, object) \
    static struct Register##object { \
        Register##object() { \
            Registry::instance().register_object(name, new object()); \
        } \
    } register_##object

class Square final : public Object {
private:
    float length;
public:
    void describe() override {
        std::cout << "A square has four sides that are of equal length\n";
    }

    void parse(const std::vector<float> &args) override {
        if (args.size() == 0) {
            describe();
        } else if (args.size() == 1) {
           length = args[0];
           std::cout << "perimeter: " << perimeter() << " area: " << area() << '\n';
        } else {
            throw std::runtime_error("Usage: describe_object square [length]");
        }
    }
    
    float area() override {
        return length * length;
    }

    float perimeter() override {
        return 4 * length;
    }
};
REGISTER("square", Square);

class Circle final : public Object {
private:
    float radius;
public:
    void describe() override {
        std::cout << "A circle has a radius\n";
    }

    void parse(const std::vector<float> &args) override {
        if (args.size() == 0) {
            describe();
        } else if (args.size() == 1) {
            radius = args[0];
            std::cout << "perimeter: " << perimeter() << " area: " << area() << '\n';
        } else {
            throw std::runtime_error("Usage: describe_object circle [radius]");
        }
    }

    float area() override {
        return std::numbers::pi_v<float> * radius * radius;
    }

    float perimeter() override {
        return 2 * std::numbers::pi_v<float> * radius;
    }

    ~Circle() = default;
};
REGISTER("circle", Circle);

class Rectangle final : public Object {
private:
    float height;
    float width;
public:
    void describe() override {
        std::cout << "A rectangle has 4 sides broken into 2 side pairs"
            " of equal length and are parallel\n";
    }

    void parse(const std::vector<float> &args) override {
        if (args.size() == 0) {
            describe();
        } else if (args.size() == 2) {
            height = args[0];
            width = args[1];
            std::cout << "perimeter: " << perimeter() << " area: " << area() << '\n';
        } else {
            throw std::runtime_error("Usage: describe_object rect [height width]");
        }
    }

    float area() override {
        return height * width;
    }

    float perimeter() override {
        return 2 * (height + width);
    }
};
REGISTER("rect", Rectangle);
