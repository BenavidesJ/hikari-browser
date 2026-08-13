#include "net/platform/SocketPlatform.h"

#ifdef _WIN32

#include <winsock2.h>

#else

// POSIX systems (macOS, Linux, etc.)
// No initialization is required.

#endif

namespace hikari
{
  void SocketPlatform::initialize()
  {
#ifdef _WIN32
    WSDATA data{};

    WSAStartup(
      MAKEWORD(2,2),
      &data
    );
#endif
  }

  void SocketPlatform::cleanup()
  {
#ifdef _WIN32
    WSACleanup();
#endif
  }
}