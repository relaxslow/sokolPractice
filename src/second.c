#define SOKOL_IMPL
#define SOKOL_APP_IMPL
#define SOKOL_METAL
#include<stdio.h>
#include "sokol_app.h"
#include "sokol_log.h"

#include "sokol_gfx.h"
#include "sokol_glue.h"
//test git
static struct {
    sg_pass_action pass_action;
    sg_bindings bindings;
    sg_pipeline pipeline;
}state;

void init(void) {
    sg_setup(&(sg_desc){
        .environment = sglue_environment(),
        .logger.func = slog_func
    });
    state . pass_action = (sg_pass_action) {
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = {0.1f, 0.2f, 0.3f, 1.0f},
        },
    };

}

void frame(void) {
    sg_begin_pass(&(sg_pass){
        .action = state . pass_action,
        .swapchain = sglue_swapchain(),
    });

    sg_end_pass();
    sg_commit();
}

void cleanup(void) {
    sg_shutdown();
}

void event(const sapp_event* e) {
    if(e->type == SAPP_EVENTTYPE_KEY_DOWN) {
        if(e->key_code == SAPP_KEYCODE_ESCAPE) {
            sapp_request_quit();
        }
    }
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
