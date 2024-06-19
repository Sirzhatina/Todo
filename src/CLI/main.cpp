#include <Core/IClient.hpp>
#include "Client.hpp"
#include <memory>

int main(int argc, char* argv[]) {
    std::unique_ptr<IClient> app = std::make_unique<Client>();

    app->parseCmd(argc, argv);

    return static_cast<int>(app->run());
}