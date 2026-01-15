#include "shapes.hpp"

int main(int argc, char *argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Usage: describe_object object [args...]";
            return 1;
        }
        auto object = Registry::instance().get(argv[1]);
        if (!object) {
            std::cerr << argv[1] << " is not registered\n";
            return 1;
        }
        std::vector<float> args;
        for (int i = 2; i < argc; i++) {
            args.push_back(std::stof(argv[i]));
        }
        object->parse(args);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}
