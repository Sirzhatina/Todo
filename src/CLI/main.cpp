#include <iostream>
#include <boost/program_options.hpp>
#include <format>
#include <string>

struct Task {
    std::string name;
    std::string description;

    bool isComplete{false};
};


int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    constexpr auto programUsage = "Usage: program add [options]";

    if (argc < 2) {
        std::cerr << std::format("{}\n", programUsage);
        return EXIT_FAILURE;
    }

    if (std::string{argv[1]} != "add") {
        std::cerr << "Unknown command\n";
        return EXIT_FAILURE;
    }

    po::options_description addOptions{std::format("{}. Options are", programUsage)};
    addOptions.add_options()
        ("name,n", "Task name")
        ("description,d", "Task description")
        ("help,h", "shows this message");

    po::variables_map vm;
    po::store(po::command_line_parser{
        std::vector<std::string>{argv + 2, argv + argc}
        }.options(addOptions)
        .run(), 
        vm
    );
    po::notify(vm);

    if (vm.size() == 0 || vm.count("help")) {
        std::cout << addOptions;
        return 0;
    }
}