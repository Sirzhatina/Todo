#include "Client.hpp"
#include <iostream>
#include <format>
#include <boost/program_options/parsers.hpp>
#include "Task.hpp"

namespace po = boost::program_options;

Client::Client(int argc, char* argv[])
: m_args{argv + 2, argv + argc}
, m_addOptions{std::format("{}. Options are", m_programUsage)} {
    m_addOptions.add_options()
        ("name,n", po::value<std::string>(), "Task name")
        ("description,d", po::value<std::string>(), "Task description")
        ("help,h", "shows this message");
}


std::optional<Client> Client::makeClient(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << std::format("{}\n", m_programUsage);
        return {};
    }

    if (std::string{argv[1]} != "add") {
        std::cerr << "Unknown command\n";
        return {};
    }

    return Client{argc, argv};
}

int Client::run() {
    po::store(po::command_line_parser{m_args
        }.options(m_addOptions)
        .run(),
        m_vm
    );
    po::notify(m_vm);
    
    if (!m_vm.contains("name") && !m_vm.contains("description")) {
        if (m_vm.contains("help")) {
            std::cout << m_addOptions << std::endl;
            return EXIT_SUCCESS;
        }
        std::cerr << "Either name or description must be passed." << std::endl;
        return EXIT_FAILURE;
    }

    Task t;
    t.name = m_vm["name"].as<std::string>();
    t.description = m_vm["description"].as<std::string>();

    return EXIT_SUCCESS;
}