#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>

#include <iostream>

using std::cout;
using std::endl;

struct mpi_server: hpx::components::simple_component_base<mpi_server>
{
    void print_num(int i) {
        cout << "printing " << i << endl;
    }
    HPX_DEFINE_COMPONENT_DIRECT_ACTION(mpi_server, print_num, print_num_action);
};

typedef hpx::components::simple_component<mpi_server> mpi_server_type;
HPX_REGISTER_COMPONENT(mpi_server_type, mpi_server);

typedef mpi_server::print_num_action print_num_action;
HPX_REGISTER_ACTION(print_num_action);

struct mpi_client: hpx::components::client_base<mpi_client, mpi_server>
{
    void print_num(int i) {
        mpi_server::print_num_action act;
        hpx::async(act, get_id(), i);
    }

};

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

