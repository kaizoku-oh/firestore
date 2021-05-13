#include <stdio.h>
#include <esp_log.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "firestore.h"
#include "app_wifi.h"

static void _app_main_firestore_task(void *);
static void _app_main_update_document(void);

#define APP_MAIN_TAG                             "APP_MAIN"

#define APP_MAIN_FIRESTORE_TASK_STACK_SIZE       10240
#define APP_MAIN_FIRESTORE_TASK_PRIORITY         4
#define APP_MAIN_FIRESTORE_PERIOD_MS             1000

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

void app_main(void)
{
  /* Block until connected to WiFi */
  app_wifi_init();
  app_wifi_wait();

  xTaskCreate(_app_main_firestore_task,
              "firestore",
              APP_MAIN_FIRESTORE_TASK_STACK_SIZE,
              NULL,
              APP_MAIN_FIRESTORE_TASK_PRIORITY,
              NULL);
}

static void _app_main_firestore_task(void *pvParameter)
{
  firestore_init();
  while(1)
  {
    _app_main_update_document();
    vTaskDelay(APP_MAIN_FIRESTORE_PERIOD_MS / portTICK_PERIOD_MS);
  }
}

static void _app_main_update_document(void)
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
