#include "AgentService.h"

int main(int argc, char const *argv[])
{
    int fd = start_service();
    int err = accept_connections(fd);
    close(fd);
    return 0;
}
