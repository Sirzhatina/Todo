#pragma once

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <vector>
#include <memory>

class AbstractCommand {
public:
    AbstractCommand(std::string_view commandName, 
                    std::string_view optionsDescription = mDEFAULT_DESCRIPTION)
    : m_commandName{commandName}
    , m_descr{optionsDescription.data()} { }

    virtual ~AbstractCommand() = default;

    virtual std::string_view getCommandName() const = 0;

    void storeOptions(std::vector<char*> args);

protected:

    boost::program_options::options_description m_descr;
    boost::program_options::variables_map       m_vm;
    std::string_view                            m_commandName;


    static constexpr std::string_view mDEFAULT_DESCRIPTION = "Allowed options";
};