#include "AgentService.h"

int main(int argc, char const *argv[])
{
    int fd = start_service();
    if (fd == -1)
        return 1;

    close(fd);
    return 0;
}
