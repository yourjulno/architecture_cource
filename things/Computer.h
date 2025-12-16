#pragma once

#include <things/Thing.h>

#include <utility>

namespace jul::animals
{

class Computer: public Thing
{
public:

    Computer(std::string name, int number): Thing(std::move(name), number){}
};

}
