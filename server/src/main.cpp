#include <fmt/base.h>

#include "network/Listener.hpp"

#include "Windows.h"

class GameSession : public Session
{
public:
    void OnConnected(net::endpoint endpoint) override
    {

    }

    void OnDisconnected(net::endpoint endpoint) override
    {

    }

    void OnReceived(std::span<char> buffer, unsigned length) override
    {

    }

    void OnSent(unsigned length) override
    {

    }
};

int main()
{
    net::native::initialize();
    auto endpoint = net::endpoint(net::ip_address::loopback, 8888);
    auto listener = Listener::Open<GameSession>();
    listener->Run(endpoint);
    fmt::println("Server is running on {}", endpoint.to_string());

    getchar();
}