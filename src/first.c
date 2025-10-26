#define SOKOL_IMPL
#define SOKOL_APP_IMPL
#define SOKOL_METAL
#include<stdio.h>
#include "sokol_app.h"
#include "sokol_log.h"


void init(void) {
}

void frame(void) {
}

void cleanup(void) {
}

void event(const sapp_event* e) {
}
sapp_desc sokol_main(int argc, char* argv[]) {
    printf("hello sokol");
    return (sapp_desc) {
        .width = 800,
        .height = 600,
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
        .window_title = "First",
        .logger.func = slog_func,
    };
}
