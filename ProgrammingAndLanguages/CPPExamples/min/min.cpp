#include <iostream>
#include <sstream>

using namespace std;

int main() {
    uint32_t j = 0;
    uint32_t k = 8;
    uint32_t i = min(j, k);
    cout << "min is " << i << endl;

    return 0;
}
