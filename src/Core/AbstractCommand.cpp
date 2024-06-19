#include "AbstractCommand.hpp"


void AbstractCommand:: storeOptions(std::vector<char*> args) {
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