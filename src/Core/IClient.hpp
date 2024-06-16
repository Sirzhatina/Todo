#pragma once

enum class err {ok, not_ok};

class IClient {
public:
    virtual void parseCmd(int argc, char* argv[]) = 0;

    virtual err run() = 0;
};