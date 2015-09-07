#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>

#include <iostream>

using std::cout;
using std::endl;

void print()
{
    cout << "hello world" << endl;
}

int hpx_main(int argc, char **argv) 
{
    for(int i = 0; i < 5; i++) {
        hpx::apply(print);
    }
    return hpx::finalize();
}

int main(int argc, char **argv) 
{
    return hpx::init(argc, argv);
}

