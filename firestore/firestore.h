#ifndef __FIRESTORE_H__
#define __FIRESTORE_H__

#include <stdint.h>

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

#endif /* __FIRESTORE_H__ */