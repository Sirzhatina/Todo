#pragma once

#include "AbstractCommand.hpp"

class AddCommand final : public AbstractCommand {
public:
    AddCommand(std::string_view optionsDescription = mDEFAULT_DESCRIPTION)
    : AbstractCommand{"add", optionsDescription} { }

    std::string_view getCommandName() const final { return m_commandName; }
};