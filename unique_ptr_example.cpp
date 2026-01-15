#include <memory>

int main() {
    std::unique_ptr<int> a(new int());
    *a = 10;
    return *a;
}
