#pragma once

#include <string>

namespace jul::animals
{

class IInventory
{
public:

    virtual ~IInventory() = default;

    [[nodiscard]] virtual std::string get_name() const = 0;

    [[nodiscard]] virtual int number() const = 0;
};

}
