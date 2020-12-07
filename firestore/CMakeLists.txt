idf_component_register(
    SRCS "firestore.c"
    INCLUDE_DIRS . ../examples/platformio/include
    REQUIRES log freertos esp_http_client
)
