#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace hikari
{
    class URL
    {
    public:
        explicit URL(std::string_view url);

        const std::string& scheme() const;
        const std::string& host() const;
        std::uint16_t port() const;
        const std::string& path() const;

    private:
        std::string m_scheme;
        std::string m_host;
        std::uint16_t m_port;
        std::string m_path;
    };
}