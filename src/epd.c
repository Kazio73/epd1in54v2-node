#include <node_api.h>
#include <assert.h>
#include <stdio.h>
#include "DEV_Config.h"
#include "epd.h"

#define DECLARE_NAPI_METHOD(name, func)        \
    { name, 0, func, 0, 0, 0, napi_default, 0 }

// --- Wrappers ---

napi_value Init(napi_env env, napi_callback_info info) {
    printf("📦 EPD_Init() called\n");
    DEV_Module_Init();
    EPD_Init();
    return NULL;
}

napi_value InitPartial(napi_env env, napi_callback_info info) {
    printf("📦 EPD_Init_Partial() called\n");
    DEV_Module_Init();
    EPD_Init_Partial();
    return NULL;
}

napi_value Clear(napi_env env, napi_callback_info info) {
    printf("🧽 EPD_Clear() called\n");
    EPD_Clear();
    return NULL;
}

napi_value Display(napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 1;
    napi_value args[1];
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    assert(status == napi_ok);

    void* data;
    size_t length;
    status = napi_get_buffer_info(env, args[0], &data, &length);
    assert(status == napi_ok);

    printf("🖼️ EPD_Display() - length=%zu\n", length);
    EPD_Display((uint8_t*)data);
    return NULL;
}

napi_value DisplayBase(napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 1;
    napi_value args[1];
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    assert(status == napi_ok);

    void* data;
    size_t length;
    status = napi_get_buffer_info(env, args[0], &data, &length);
    assert(status == napi_ok);

    printf("📄 EPD_DisplayBase() - length=%zu\n", length);
    EPD_DisplayBase((uint8_t*)data);
    return NULL;
}

napi_value DisplayPartial(napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 1;
    napi_value args[1];
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    assert(status == napi_ok);

    void* data;
    size_t length;
    status = napi_get_buffer_info(env, args[0], &data, &length);
    assert(status == napi_ok);

    printf("🧩 EPD_DisplayPartial() - length=%zu\n", length);
    EPD_DisplayPartial((uint8_t*)data);
    return NULL;
}

napi_value Sleep(napi_env env, napi_callback_info info) {
    printf("💤 EPD_Sleep() called\n");
    EPD_Sleep();
    return NULL;
}

// --- Node.js export ---

napi_value InitAddon(napi_env env, napi_value exports) {
    napi_status status;

    napi_property_descriptor descriptors[] = {
        DECLARE_NAPI_METHOD("init", Init),
        DECLARE_NAPI_METHOD("initPartial", InitPartial),
        DECLARE_NAPI_METHOD("clear", Clear),
        DECLARE_NAPI_METHOD("display", Display),
        DECLARE_NAPI_METHOD("displayBase", DisplayBase),
        DECLARE_NAPI_METHOD("displayPartial", DisplayPartial),
        DECLARE_NAPI_METHOD("sleep", Sleep),
    };

    status = napi_define_properties(env, exports, sizeof(descriptors) / sizeof(*descriptors), descriptors);
    assert(status == napi_ok);
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, InitAddon)