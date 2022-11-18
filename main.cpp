#include <iostream>
#include "MyList.h"

using namespace std;
int main() {
    int arr [3] = {1,2,3};
    MyList<int> l(arr,3);
    cout << l;
    l.push_front(7);
    cout << l;
    l.pop_back();
    cout << l;
    l.insert(1,45);
    cout << l;
    return 0;
}
