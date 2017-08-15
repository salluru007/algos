#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

using namespace std;

#include "Stack.h"
#include "stack-impl.hpp"

int main(int argc, char* argv[]) {

    Stack<int> i1;
    assert (i1.size() == 0);
    assert (i1.isEmpty());

    i1.push(1);
    assert (i1.size() == 1);
    assert (!i1.isEmpty());

    i1.push(2);
    i1.push(3);

    Stack<int> i2 = i1;
    assert (i2.size() == 3);

    i1.pop();
    assert (i1.size() == 2);
    assert (i2.size() == 3);

    i1.display();
    i2.display();

    Stack<string> s;
    s.push("third");
    s.push("second");
    s.push("first");
    s.display();

    return EXIT_SUCCESS;
}
