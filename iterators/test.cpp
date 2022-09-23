
#include <map>

int main() {
    std::map<int, int> m;

    m.insert(std::make_pair<int, int>(1, 1));
    m.insert(std::make_pair<int, int>(2, 2));
    m.insert(std::make_pair<int, int>(3, 3));

    std::map<int, int>::iterator it = m.begin();
    std::map<int, int>::iterator const it2(it);

    it2 = it;
    return 0;
} 