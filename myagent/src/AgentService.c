#include "AgentService.h"

/**
 * @brief Create a new AF_UNIX socket.
 * 
 * @return int Socket file desciptor
 */
int start_service() {
    int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_un name;
    name.sun_family = AF_UNIX;
    
    int ran_num = random();
    char path[108];
    strcpy(path, UN_SOCKET_BASENAME);

    char s_num[sizeof(UN_SOCKET_BASENAME)];
    sprintf(s_num, "%d", ran_num);
    strcat(path, s_num);
    strcat(path, ".sock");

    // copy build path to structure
    strcpy(name.sun_path, path);

    printf("Socket file descriptor: %d\n", socket_fd);
    printf("New AF_UNIX socket created at: %s\n", path);
    unlink(name.sun_path);
    int bind_err = bind(socket_fd, (const struct sockaddr *)&name, sizeof(struct sockaddr_un));
    if (bind_err == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

/**
 * @brief Begin accepting connects from sockets.
 * 
 * @param socket_fd The receving socket file descriptor.
 * @return int 
 */
int accept_connections(int socket_fd) {
    int listen_err = listen(socket_fd, 20);
    if (listen_err == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    char buffer[12];
    int new_connection;

    // Connection handling loop
    for (;;) {
        int new_connection = accept(socket_fd, NULL, NULL);
        if (new_connection == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection with file descriptor: %d\n", new_connection);

        // Reading loop
        int result = 0;
        for (;;) {
            int read_data = read(new_connection, buffer, 12);
            if (read_data == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            
            printf("> %s\n", buffer);
            close(new_connection);
            break;            
        } 

        break;
    }

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
