#include "AgentService.h"

/**
 * @brief Create a new AF_UNIX socket.
 * 
 * @return int Socket file desciptor
 */
int start_service() {
    int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        print_error(SOCKET_INIT_FAILED);
        return socket_fd;
    }

    struct sockaddr_un name;
    name.sun_family = AF_UNIX;
    
    int ran_num = random();
    char path[108];
    strcpy(path, UN_SOCKET_BASENAME);
    sprintf(path, "%d", ran_num);
    strcpy(name.sun_path, path);

    bind(socket_fd, (const struct sockaddr *)&name, sizeof name);
    return socket_fd;
}

/**
 * @brief Begin accepting connects from sockets.
 * 
 * @param socket_fd The receving socket file descriptor.
 * @return int 
 */
int accect_connections(int socket_fd) {
    //struct sockaddr addr;
    //accept(socket_fd, addr, sizeof addr); 
    return 0;
}

/**
 * @brief Begin receving data.
 * 
 * @param socket_fd The socket file descriptor.
 * @return int 
 */
int recv_data(int socket_fd) {
    return 0;
}
