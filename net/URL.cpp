#include "net/URL.h"

#include <charconv>
#include <system_error>

namespace hikari
{
    URL::URL(std::string_view url)
        : m_port(80)
    {
        auto scheme_end = url.find("://");

        if (scheme_end == std::string_view::npos)
        {
            return;
        }

        m_scheme = url.substr(0, scheme_end);

        auto host_start = scheme_end + 3;
        auto path_start = url.find("/", host_start);
        auto port_start = url.find(":", host_start);

        if (port_start != std::string_view::npos &&
            (path_start == std::string_view::npos || port_start < path_start))
        {
            auto port_end = path_start == std::string_view::npos
                ? url.size()
                : path_start;

            auto port = url.substr(
                port_start + 1,
                port_end - port_start - 1
            );

            std::uint16_t parsed_port = 0;

            auto [ptr, error] = std::from_chars(
                port.data(),
                port.data() + port.size(),
                parsed_port
            );

            if (error != std::errc{} ||
                ptr != port.data() + port.size())
            {
                return;
            }

            m_port = parsed_port;
        }

        auto host_end = port_start != std::string_view::npos &&
                        (path_start == std::string_view::npos ||
                         port_start < path_start)
            ? port_start
            : path_start;

        if (host_end == std::string_view::npos)
        {
            m_host = url.substr(host_start);
        }
        else
        {
            m_host = url.substr(
                host_start,
                host_end - host_start
            );
        }

        if (path_start == std::string_view::npos)
        {
            m_path = "/";
        }
        else
        {
            m_path = url.substr(path_start);
        }
    }

    const std::string& URL::scheme() const
    {
        return m_scheme;
    }

    const std::string& URL::host() const
    {
        return m_host;
    }

    std::uint16_t URL::port() const
    {
        return m_port;
    }

    const std::string& URL::path() const
    {
        return m_path;
    }
}