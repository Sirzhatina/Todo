#pragma once

#include <vector>
#include <string_view>
#include <iostream>
#include <Core/IClient.hpp>
#include <boost/program_options.hpp>

#define po boost::program_options

class Client final : public IClient {
public:

    Client() {

    }
    
    void parseCmd(int argc, char* argv[]) final {
        std::cout << "parseCmd is not implemented yet" << std::endl;
    }

    err run() final {
        std::cout << "run is not implemented yet" << std::endl;
        return err::ok;
    }

private:

    po::options_description descr{"Allowed options"};
};

#undef po