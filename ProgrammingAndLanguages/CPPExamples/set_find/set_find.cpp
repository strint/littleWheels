#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

struct Item {
    string id;
    int rank;
    
    Item() {
        rank = 0;
    }

    bool operator < (const Item &item) const {
    	if (rank < item.rank) {
            return true;
        }
        return false;
    }

    bool operator == (const Item &item) const {
        return id == item.id;
    }
    
    string toString() const {
        ostringstream str;
        str << "id " << id
            << " rank " << rank;
        return str.str();
    }
};

int main() {
    Item i2;
    i2.id = "b";
    i2.rank = 2;

    Item i1;
    i1.id = "a";
    i1.rank = 1;

    Item i3;
    i3.id = "c";
    i3.rank = 3;

    Item i4;
    i4.id = "c";
    i4.rank = 1;
    
    set<Item> i_set;
    i_set.insert(i2);
    i_set.insert(i1);
    i_set.insert(i3);

    for (auto &i : i_set) {
        cout << i.toString() << endl;
    }
    auto f_i = i_set.find(i4);
    if (f_i != i_set.end()) {
        cout << " src " << i4.toString() << endl;
        cout << " find " << f_i->toString() << endl;
    } else {
        cout << " can not find " << i4.toString() << endl;
    }

    if (i4 == i3) {
        cout << " i4 == i3" << endl;
    } else {
        cout << " i4 == i3" << endl;
    }

    if (i4 == i1) {
        cout << " i4 == i1" << endl;
    } else {
        cout << " i4 != i1" << endl;
    }

    return 0;
}
