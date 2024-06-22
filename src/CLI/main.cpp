#include <iostream>
#include "Client.hpp"
#include <boost/program_options.hpp>
int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    // Task newTask;
    // if (vm.count("name")) {
    //     newTask.name = vm["name"].as<std::string>();
    // }
    // if (vm.count("description")) {
    //     newTask.description = vm["description"].as<std::string>();
    // }

    auto app = Client::makeClient(argc, argv);
    if (!app) {
        std::cerr << "Failed creating Client" << std::endl;
        return EXIT_FAILURE;
    }
    return app->run();
}