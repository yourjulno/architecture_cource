#pragma once

#include <things/IInventory.h>
#include <iostream>
#include <utility>

namespace jul::animals
{

class Thing: public IInventory
{
    std::string name_;
    int number_;

public:

    Thing(std::string name, int number): name_(std::move(name)), number_(number){}

    [[nodiscard]] std::string get_name() const override
    {
        return name_;
    }

    [[nodiscard]] int number() const override
    {
        return number_;
    }

    virtual void get_info() const noexcept
    {
        std::cout << name_ << " под номером " << number_ << std::endl;
    }
};

}
