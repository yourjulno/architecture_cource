#pragma once

#include <things/Thing.h>

#include <utility>

namespace jul::animals
{

class Table: public Thing
{
public:

    Table(std::string name, int number): Thing(std::move(name), number){}
};

}
