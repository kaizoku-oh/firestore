#include <string.h>
#include <esp_log.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "firestore.h"
#include "app_wifi.h"

static void _firestore_task(void *);

#define APP_MAIN_TAG                             "APP_MAIN"
#define APP_MAIN_FIRESTORE_DOC_MAX_SIZE          64
#define APP_MAIN_FIRESTORE_COLLECTION_ID         "devices"
#define APP_MAIN_FIRESTORE_DOCUMENT_ID           "esp32"
#define APP_MAIN_FIRESTORE_DOCUMENT_EXAMPLE      "{"                           \
                                                   "\"fields\": {"             \
                                                       "\"random\": {"         \
                                                       "\"integerValue\": 158" \
                                                     "},"                      \
                                                   "}"                         \
                                                 "}"

static uint32_t u32DocLength;
static char tcDoc[APP_MAIN_FIRESTORE_DOC_MAX_SIZE];

void update_document(void)
{
  /* Format json document */
  u32DocLength = snprintf(tcDoc,
                          sizeof(tcDoc),
                          "{\"fields\":{\"random\":{\"integerValue\":%d}}}",
                          rand());
  if(u32DocLength > 0)
  {
    if(FIRESTORE_OK == firestore_update_document(APP_MAIN_FIRESTORE_COLLECTION_ID,
                                                 APP_MAIN_FIRESTORE_DOCUMENT_ID,
                                                 tcDoc,
                                                 &u32DocLength))
    {
      ESP_LOGI(APP_MAIN_TAG, "Document updated successfully");
      ESP_LOGI(APP_MAIN_TAG, "Updated document length: %d", u32DocLength);
      ESP_LOGI(APP_MAIN_TAG, "Updated document content:\r\n%.*s", u32DocLength, tcDoc);
    }
    else
    {
      ESP_LOGE(APP_MAIN_TAG, "Couldn't update document");
    }
  }
  else
  {
    ESP_LOGE(APP_MAIN_TAG, "Couldn't format document");
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
  app_wifi_init();
  app_wifi_wait();

  xTaskCreate(_firestore_task, "firestore", 10240, NULL, 4, NULL);
}
