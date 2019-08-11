// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

/*Exercise 2.1
 * The size of a vector refers to the number of elements that are currently 
 * in the vector. Whereas the capacity of a vector refers to the largest size
 * it can be before it needs to reallocate memory
 * 
 * 
 * A vector's capacity grows the way it does because each time the vector's
 * capacity increases, the elements which are present in the vector are copied
 * in order to minimize the cost of copying, the vector's capacity grows exponentially
 * */