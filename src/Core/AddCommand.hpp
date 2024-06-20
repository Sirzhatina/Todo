#pragma once

#include "AbstractCommand.hpp"

class AddCommand final : public AbstractCommand {
public:
    AddCommand(std::string_view optionsDescription = mDEFAULT_DESCRIPTION)
    : AbstractCommand{"add", optionsDescription} {
        m_descr.add_options()
            ("name,n", "The name of the new task")
            ("description,d", "The description of the new taks");
    }

    std::string_view getCommandName() const final { return m_commandName; }
};