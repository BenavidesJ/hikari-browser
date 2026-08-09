#include "browser/Browser.h"
#include "net/URL.h"

#include <iostream>

int main(int argc, char** argv)
{
    hikari::URL url("http://example.org");

    std::cout << "Scheme: " << url.scheme() << '\n';
    std::cout << "Host:   " << url.host() << '\n';
    std::cout << "Port:   " << url.port() << '\n';
    std::cout << "Path:   " << url.path() << '\n';

    return 0;
}