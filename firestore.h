/*
  Usage example:

  #include "firestore.h"

  #define NEW_DOCUMENT_CONTENT "{"                                                  \
                                 "\"fields\": {"                                    \
                                     "\"last_seen_connected\": {"                   \
                                     "\"timestampValue\": \"2021-11-13T20:44:30Z\"" \
                                   "},"                                             \
                                   "\"firmware_version\": {"                        \
                                     "\"stringValue\": \"v2.0.0\""                  \
                                   "},"                                             \
                                   "\"send_frequency\": {"                          \
                                     "\"integerValue\": \"6\""                      \
                                   "},"                                             \
                                   "\"device_id\": {"                               \
                                     "\"stringValue\": \"wrover-32\""               \
                                   "},"                                             \
                                   "\"connection_status\": {"                       \
                                     "\"stringValue\": \"connected\""               \
                                   "}"                                              \
                                 "}"                                                \
                               "}"

  firestore_init();

  // Get Collection
  void get_collection(void)
  {
    char *pcCollection;
    uint32_t u32CollectionLen;

    if(FIRESTORE_OK == firestore_get_collection("devices", &pcCollection, &u32CollectionLen))
    {
      ESP_LOGI(TAG, "Collection length: %d", u32CollectionLen);
      ESP_LOGI(TAG, "Collection content:\r\n%.*s", u32CollectionLen, pcCollection);
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't get collection");
    }
  }
  
  // Get Document
  void get_document(void)
  {
    char *pcDocument;
    uint32_t u32DocumentLen;
  
    if(FIRESTORE_OK == firestore_get_document("devices", "esp32", &pcDocument, &u32DocumentLen))
    {
      ESP_LOGI(TAG, "Document length: %d", u32DocumentLen);
      ESP_LOGI(TAG, "Document content:\r\n%.*s", u32DocumentLen, pcDocument);
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't get document");
    }
  }

  // Update Document
  void update_document(void)
  {
    char tcDocument[320];
    uint32_t u32DocumentLen;

    memcpy(tcDocument, NEW_DOCUMENT_CONTENT, sizeof(NEW_DOCUMENT_CONTENT));
    if(FIRESTORE_OK == firestore_update_document("devices",
                                                 "esp8266",
                                                 tcDocument,
                                                 &u32DocumentLen))
    {
      ESP_LOGI(TAG, "Updated document length: %d", u32DocumentLen);
      ESP_LOGI(TAG, "Updated document content:\r\n%.*s", u32DocumentLen, tcDocument);
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't update document");
    }
  }

  // Add Document
  void add_document(void)
  {
    char tcDocument[320];
    uint32_t u32DocumentLen;

    memcpy(tcDocument, NEW_DOCUMENT_CONTENT, sizeof(NEW_DOCUMENT_CONTENT));
    if(FIRESTORE_OK == firestore_add_document("devices",
                                              "new_device_id",
                                              tcDocument,
                                              &u32DocumentLen))
    {
      ESP_LOGI(TAG, "Added document length: %d", u32DocumentLen);
      ESP_LOGI(TAG, "Added document content:\r\n%.*s", u32DocumentLen, tcDocument);
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't add document");
    }
  }

  // Delete Document
  void delete_document(void)
  {
    if(FIRESTORE_OK == firestore_delete_document("devices", "new_device_id"))
    {
      ESP_LOGI(TAG, "Document deleted successfully");
    }
    else
    {
      ESP_LOGE(TAG, "Couldn't delete document");
    }
  }
*/

#ifndef _FIRESTORE_H_
#define _FIRESTORE_H_

typedef enum
{
  FIRESTORE_OK                = 0,               /**< No error, everything OK  */
  FIRESTORE_ERR               = -1,              /**< Generic error            */
  FIRESTORE_ERR_HTTP          = -2,              /**< Timeout                  */
  FIRESTORE_ERR_ARG           = -4,              /**< Illegal argument         */
  FIRESTORE_ERR_UNHANDLED     = -5,              /**< Unhandled feature/option */
  FIRESTORE_ERR_MCU           = -6,              /**< MCU error                */
  FIRESTORE_ERR_OS            = -7,              /**< Operating system error   */
}firestore_err_t;

firestore_err_t firestore_init(void);
firestore_err_t firestore_get_collection(char *pcCollectionId,
                                         char **pcDocs,
                                         uint32_t *pu32DocsLen);
firestore_err_t firestore_get_document(char *pcCollectionId,
                                       char *pcDocumentId,
                                       char **ppcDocument,
                                       uint32_t *pu32DocumentLen);
firestore_err_t firestore_add_document(char *pcCollectionId,
                                       char *pcDocumentId,
                                       char *pcDocument,
                                       uint32_t *pu32DocumentLen);
firestore_err_t firestore_update_document(char *pcCollectionId,
                                          char *pcDocumentId,
                                          char *pcDocument,
                                          uint32_t *pu32DocumentLen);
firestore_err_t firestore_delete_document(char *pcCollectionId, char *pcDocumentId);

#endif /* _FIRESTORE_H_ */