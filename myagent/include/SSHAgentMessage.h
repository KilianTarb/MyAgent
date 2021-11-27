#include <stdint.h>

// Server Response Types
#define SSH_AGENT_FAILURE 5
#define SSH_AGENT_SUCCESS 6
#define SSH_AGENT_EXTENTION_FAILURE 28
#define SSH_AGENT_IDENTITIES_ANSWER 12
#define SSH_AGENT_SIGN_RESPONSE 14

/**
 * @brief Generic transport message.
 */
struct SSHAgentMessage
{
    /**
     * Message length
     */
    uint32_t length;

    /**
     * Message type as defined by the IETF 
     */
    char type;

    /**
     * Contents of the message.
     */
    char *body;
};
