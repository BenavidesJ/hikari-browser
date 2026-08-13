#pragma once

#include <cstdint>
#include <string>

namespace hikari
{
    class TCPSocket
    {
    public:
        TCPSocket();

        void connect(
            const std::string& host,
            std::uint16_t port
        );

    private:
#ifdef _WIN32
        using SocketHandle = std::uintptr_t;
        static constexpr SocketHandle InvalidSocket = ~SocketHandle{0};
#else
        using SocketHandle = int;
        static constexpr SocketHandle InvalidSocket = -1;
#endif

        SocketHandle m_socket;
    };
}