#include <microhttpd.h>
#include <stdio.h>
#include <string.h>

// Your request handler function
static int handle_request(void *cls, struct MHD_Connection *connection, const char *url,
                          const char *method, const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    const char *response = "Hello, World!\n";
    struct MHD_Response *mhd_response;
    int ret;

    mhd_response = MHD_create_response_from_data(strlen(response), (void *)response, 0, 0);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, mhd_response);
    MHD_destroy_response(mhd_response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    // Start the HTTP daemon
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8080, NULL, NULL,
                              &handle_request, NULL, MHD_OPTION_END);

    if (NULL == daemon) {
        fprintf(stderr, "Failed to start the server.\n");
        return 1;
    }

    getchar();  // Wait for a key press to stop the server

    // Stop the HTTP daemon
    MHD_stop_daemon(daemon);

    return 0;
}
