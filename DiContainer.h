#pragma once

#include <map>
#include <typeindex>
#include <functional>
#include <any>
#include <memory>

namespace jul::animals
{
class DiContainer
{
    std::map<std::type_index, std::function<std::any()>> factories_;
    std::map<std::type_index, std::any> singletons_;

public:

    template<typename Interface, typename Impl>
    void register_type(bool is_singleton = false)
    {
        auto factory = []()
        {
            return std::make_shared<Impl>();
        };

        if (is_singleton) {
            singletons_[std::type_index(typeid(Interface))] = factory();
        }
        else {
            factories_[std::type_index(typeid(Interface))] = factory;
        }
    }

    template<typename Interface>
    void register_factory(std::function<std::shared_ptr<Interface>()> factory, bool singleton = false)
    {
        if (singleton) {
            singletons_[std::type_index(typeid(Interface))] = factory();
        } else {
            factories_[std::type_index(typeid(Interface))] = [factory]() -> std::any {
                return factory();
            };
        }
    }

    template<typename T>
    std::shared_ptr<T> resolve()
    {
        auto type = std::type_index(typeid(T));

        auto singletonIt = singletons_.find(type);
        if (singletonIt != singletons_.end()) {
            return std::any_cast<std::shared_ptr<T>>(singletonIt->second);
        }

        auto factoryIt = factories_.find(type);
        if (factoryIt != factories_.end()) {
            return std::any_cast<std::shared_ptr<T>>(factoryIt->second());
        }

        throw std::runtime_error("Dependency not registered: " + std::string(typeid(T).name()));
    }

    template<typename T>
    [[nodiscard]] bool isRegistered() const {
        auto type = std::type_index(typeid(T));
        return factories_.count(type) > 0 || singletons_.count(type) > 0;
    }
};

}