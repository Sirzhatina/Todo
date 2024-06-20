#pragma once

#include <vector>
#include <string_view>
#include <iostream>
#include <Core/IClient.hpp>
#include <Core/AbstractCommand.hpp>

class Client final : public IClient {
public:

    Client() {

    }
    
    void parseCmd(int argc, char* argv[]) final {
        if (argc < 2) {
            std::cerr << "Usage: program command [options]...";
            throw std::runtime_error{"Not enough arguments"};
        }

        m_executionCommand = AbstractCommand::makeCommand(argv[1]);

        m_executionCommand->storeOptions(std::vector<char*>{argv + 2, argv + argc});
    }

    err run() final {
        std::cout << "run is not implemented yet" << std::endl;
        return err::not_ok;
    }

private:
    std::unique_ptr<AbstractCommand> m_executionCommand;
};