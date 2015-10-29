# include <vector>
# include <string>
# include <ifstream>;

class GroceryList {
public:
    GroceryList(const string& filename);

    /* ... other member functions ... */

    string getItemAt(int index) const; // Problem: No longer const
private:
    mutable vector<string> data;
    mutable ifstream sourceStream;
};

GroceryList::GroceryList(const string& filename) {
    sourceStream.open(filename.c_str()); // Open the file.
}

string GroceryList::getItemAt(int index) const {
    /* Read in enough data to satisfy the request.  If we've already read it
     * in, this loop will not execute and we won't read any data.
     */
    //lazy evaluation
    while(index >= data.length()) {
        string line;
        getline(sourceStream, line);

        data.push_back(line);
    }
    return data[index];
}
