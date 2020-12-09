idf_component_register(
    SRCS "firestore.c"
    INCLUDE_DIRS . ../examples/pio-esp-idf/include ../examples/pio-esp-arduino/include
    REQUIRES log freertos esp_http_client
)
