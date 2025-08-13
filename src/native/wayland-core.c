#include <node/js_native_api.h>
#include <node/js_native_api_types.h>
#include <node/node_api.h>

napi_value hello(napi_env env) {
    napi_value result;
    napi_create_object(env,&result);
    return result;
}
