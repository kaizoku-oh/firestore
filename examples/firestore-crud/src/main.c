#include <string.h>
#include <esp_log.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "firestore.h"
#include "wifi_utils.h"

static void _firestore_task(void *);

#define TAG                                      "APP_MAIN"
#define FIRESTORE_DOC_MAX_SIZE                   64
#define FIRESTORE_COLLECTION_ID                  "devices"
#define FIRESTORE_DOCUMENT_ID                    "esp32"
#define FIRESTORE_DOCUMENT_EXAMPLE               "{"                           \
                                                   "\"fields\": {"             \
                                                       "\"random\": {"         \
                                                       "\"integerValue\": 158" \
                                                     "},"                      \
                                                   "}"                         \
                                                 "}"

static uint32_t u32DocLength;
static char tcDoc[FIRESTORE_DOC_MAX_SIZE];

void update_document(void)
{
  /* Format json document */
  u32DocLength = snprintf(tcDoc,
                          sizeof(tcDoc),
                          "{\"fields\":{\"random\":{\"integerValue\":%d}}}",
                          rand());
  if(u32DocLength > 0)
  {
    if(FIRESTORE_OK == firestore_update_document(FIRESTORE_COLLECTION_ID,
                                                 FIRESTORE_DOCUMENT_ID,
                                                 tcDoc,
                                                 &u32DocLength))
    {
      ESP_LOGI(TAG, "Document updated successfully");
      ESP_LOGI(TAG, "Updated document length: %d", u32DocLength);
      ESP_LOGI(TAG, "Updated document content:\r\n%.*s", u32DocLength, tcDoc);
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't update document");
    }
  }
  else
  {
    ESP_LOGE(TAG, "Couldn't format document");
  }
}

static void _firestore_task(void *pvParameter)
{
  firestore_init();
  while(1)
  {
    update_document();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void app_main()
{
  /* Block until connected to WiFi */
  wifi_initialise();
  wifi_wait_connected();

  xTaskCreate(_firestore_task, "firestore", 10240, NULL, 4, NULL);
}
