#include "AgentError.h"

/**
 * @brief Print err based on ID to stdout.
 * 
 * @param error_id The error ID
 */
void print_error(int error_id) {
    switch (error_id)
    {
    case SOCKET_INIT_FAILED:
        error(1, 1, "Could not initalise socket.");
        break;
    
    default:
        error(1, 1, "Error occured, but not known");
        printf("Error thrown, but not known.");
        break;
    }
}
