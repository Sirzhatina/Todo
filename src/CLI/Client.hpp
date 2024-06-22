#pragma once

#include <vector>
#include <string>
#include <optional>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>

class Client {
public:

    static std::optional<Client> makeClient(int argc, char* argv[]);

    int run();

private:

    Client(int argc, char* argv[]);

    static constexpr auto m_programUsage = "Usage: program add [options]";

    const std::string m_programName;
    const std::string m_command;

    std::vector<std::string> m_args;

    boost::program_options::options_description m_addOptions;

    boost::program_options::variables_map m_vm;
};
