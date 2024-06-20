#include "AbstractCommand.hpp"
#include "AddCommand.hpp"

AbstractCommand::AbstractCommand(std::string_view commandName, std::string_view optionsDescription)
    : m_descr{optionsDescription.data()}
    , m_commandName{commandName} { }

void AbstractCommand::storeOptions(std::vector<char*> args) {
    using namespace boost;

    program_options::store(
        program_options::parse_command_line(
            args.size(),
            args.data(),
            m_descr
        ),
        m_vm
    );
    program_options::notify(m_vm);
}

std::unique_ptr<AbstractCommand> AbstractCommand::makeCommand(std::string_view cmd) {
    if (cmd == "add") {
        return std::make_unique<AddCommand>();
    }

    throw std::invalid_argument{"No such command"};
}