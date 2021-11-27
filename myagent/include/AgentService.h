#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "AgentError.h"

#define UN_SOCKET_BASENAME "/tmp/lwsa-"

int start_service();
int accept_connections(int socket_fd);
int recv_data(int socket_fd);
