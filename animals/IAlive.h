#pragma once

#include <string>

namespace jul::animals
{

class IAlive
{
public:

    virtual ~IAlive() = default;

    virtual std::string get_name() const = 0;

    virtual int food() const = 0;
};

}
