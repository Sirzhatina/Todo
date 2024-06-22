#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    if (argc < 2) {
        std::cerr << "Usage: program command [options]\n";
        return EXIT_FAILURE;
    }

    if (std::string{argv[1]} != "add") {
        std::cerr << "Unknown command\n";
        return EXIT_FAILURE;
    }

    po::options_description descr{"Allowed options"};

    descr.add_options()
        ("name,n", "Task name")
        ("description,d", "Task description");
}