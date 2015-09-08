#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>

#include <iostream>

using std::cout;
using std::endl;

char const* mpi_basename = "mpi_object";

struct mpi_server: hpx::components::simple_component_base<mpi_server>
{
    void print_hello() {
        cout << "hello from " << hpx::find_here() << endl;
    }
    HPX_DEFINE_COMPONENT_DIRECT_ACTION(mpi_server, print_hello, print_hello_action);
};

typedef hpx::components::simple_component<mpi_server> mpi_server_type;
HPX_REGISTER_COMPONENT(mpi_server_type, mpi_server);

typedef mpi_server::print_hello_action print_hello_action;
HPX_REGISTER_ACTION(print_hello_action);

struct mpi_client: hpx::components::client_base<mpi_client, mpi_server>
{
    typedef hpx::components::client_base<mpi_client, mpi_server> base_type;

    mpi_client()
      : base_type(hpx::new_<mpi_server>( hpx::find_here() ))
    {
        hpx::register_with_basename(
            mpi_basename, get_id(), hpx::get_locality_id());
    }

    void print_hello(int id) {
        mpi_server::print_hello_action act;
        auto future_id = hpx::find_from_basename(mpi_basename, id);
        hpx::async(act, future_id.get());
    }

};

void print()
{
    cout << "hello world" << endl;
}

int hpx_main(int argc, char **argv) 
{
    //cout << "global id (of locality) = " << hpx::find_here() << endl;
    //cout << "Locality id = " << hpx::get_locality_id() << endl;
    int nodes = hpx::get_num_localities_sync();
    mpi_client mpi;
    if(hpx::get_locality_id() == 0) {
        for(int i = 0; i < nodes; i++) {
            mpi.print_hello(i);
        }
    }
    return hpx::finalize();
}

int main(int argc, char **argv) 
{
    return hpx::init(argc, argv);
}

