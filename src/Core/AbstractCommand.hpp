#pragma once

#include <boost/program_options.hpp>
#include <utility>

class AbstractCommand {
public:
    AbstractCommand(std::string_view commandName, 
                    std::string_view optionsDescription = mDEFAULT_DESCRIPTION)
    : m_commandName{commandName}
    , m_descr{optionsDescription.data()} { }

    virtual ~AbstractCommand() = default;

    virtual std::string_view getCommandName() const = 0;

protected:

    std::string_view m_commandName;

    boost::program_options::options_description m_descr;

    static constexpr std::string_view mDEFAULT_DESCRIPTION = "Allowed options";
};