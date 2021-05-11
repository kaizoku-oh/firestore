#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "firestore_config.h"

#ifndef FIRESTORE_HOSTNAME
#define FIRESTORE_HOSTNAME                       "firestore.googleapis.com"
#endif /* FIRESTORE_HOSTNAME */

#ifndef FIRESTORE_HTTP_INTERNAL_TX_BUF_SIZE
#define FIRESTORE_HTTP_INTERNAL_TX_BUF_SIZE      1024
#endif /* FIRESTORE_HTTP_INTERNAL_TX_BUF_SIZE */

#ifndef FIRESTORE_HTTP_INTERNAL_RX_BUF_SIZE
#define FIRESTORE_HTTP_INTERNAL_RX_BUF_SIZE      1024
#endif /* FIRESTORE_HTTP_INTERNAL_RX_BUF_SIZE */

#ifndef FIRESTORE_HTTP_RX_BUF_SIZE
#define FIRESTORE_HTTP_RX_BUF_SIZE               1024*2
#endif /* FIRESTORE_HTTP_RX_BUF_SIZE */

#ifndef FIRESTORE_HTTP_PATH_SIZE
#define FIRESTORE_HTTP_PATH_SIZE                 256
#endif /* FIRESTORE_HTTP_PATH_SIZE */

#ifndef FIRESTORE_FIREBASE_PROJECT_ID
#define FIRESTORE_FIREBASE_PROJECT_ID            "PUT_YOUR_FIREBASE_PROJECT_ID_HERE"
#endif /* FIRESTORE_FIREBASE_PROJECT_ID */

#ifndef FIRESTORE_FIREBASE_API_KEY
#define FIRESTORE_FIREBASE_API_KEY               "PUT_YOUR_FIREBASE_API_KEY_HERE"
#endif /* FIRESTORE_FIREBASE_API_KEY */

#ifndef FIRESTORE_FIREBASE_CA_CERT_PEM
/* openssl s_client -showcerts -verify 5 -connect edgecert.googleapis.com:443 < /dev/null */
#define FIRESTORE_FIREBASE_CA_CERT_PEM                                                            \
                                             "-----BEGIN CERTIFICATE-----\r\n"                    \
                           "MIIESjCCAzKgAwIBAgINAeO0mqGNiqmBJWlQuDANBgkqhkiG9w0BAQsFADBMMSAw\r\n" \
                           "HgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMjETMBEGA1UEChMKR2xvYmFs\r\n" \
                           "U2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjAeFw0xNzA2MTUwMDAwNDJaFw0yMTEy\r\n" \
                           "MTUwMDAwNDJaMEIxCzAJBgNVBAYTAlVTMR4wHAYDVQQKExVHb29nbGUgVHJ1c3Qg\r\n" \
                           "U2VydmljZXMxEzARBgNVBAMTCkdUUyBDQSAxTzEwggEiMA0GCSqGSIb3DQEBAQUA\r\n" \
                           "A4IBDwAwggEKAoIBAQDQGM9F1IvN05zkQO9+tN1pIRvJzzyOTHW5DzEZhD2ePCnv\r\n" \
                           "UA0Qk28FgICfKqC9EksC4T2fWBYk/jCfC3R3VZMdS/dN4ZKCEPZRrAzDsiKUDzRr\r\n" \
                           "mBBJ5wudgzndIMYcLe/RGGFl5yODIKgjEv/SJH/UL+dEaltN11BmsK+eQmMF++Ac\r\n" \
                           "xGNhr59qM/9il71I2dN8FGfcddwuaej4bXhp0LcQBbjxMcI7JP0aM3T4I+DsaxmK\r\n" \
                           "FsbjzaTNC9uzpFlgOIg7rR25xoynUxv8vNmkq7zdPGHXkxWY7oG9j+JkRyBABk7X\r\n" \
                           "rJfoucBZEqFJJSPk7XA0LKW0Y3z5oz2D0c1tJKwHAgMBAAGjggEzMIIBLzAOBgNV\r\n" \
                           "HQ8BAf8EBAMCAYYwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMBIGA1Ud\r\n" \
                           "EwEB/wQIMAYBAf8CAQAwHQYDVR0OBBYEFJjR+G4Q68+b7GCfGJAboOt9Cf0rMB8G\r\n" \
                           "A1UdIwQYMBaAFJviB1dnHB7AagbeWbSaLd/cGYYuMDUGCCsGAQUFBwEBBCkwJzAl\r\n" \
                           "BggrBgEFBQcwAYYZaHR0cDovL29jc3AucGtpLmdvb2cvZ3NyMjAyBgNVHR8EKzAp\r\n" \
                           "MCegJaAjhiFodHRwOi8vY3JsLnBraS5nb29nL2dzcjIvZ3NyMi5jcmwwPwYDVR0g\r\n" \
                           "BDgwNjA0BgZngQwBAgIwKjAoBggrBgEFBQcCARYcaHR0cHM6Ly9wa2kuZ29vZy9y\r\n" \
                           "ZXBvc2l0b3J5LzANBgkqhkiG9w0BAQsFAAOCAQEAGoA+Nnn78y6pRjd9XlQWNa7H\r\n" \
                           "TgiZ/r3RNGkmUmYHPQq6Scti9PEajvwRT2iWTHQr02fesqOqBY2ETUwgZQ+lltoN\r\n" \
                           "FvhsO9tvBCOIazpswWC9aJ9xju4tWDQH8NVU6YZZ/XteDSGU9YzJqPjY8q3MDxrz\r\n" \
                           "mqepBCf5o8mw/wJ4a2G6xzUr6Fb6T8McDO22PLRL6u3M4Tzs3A2M1j6bykJYi8wW\r\n" \
                           "IRdAvKLWZu/axBVbzYmqmwkm5zLSDW5nIAJbELCQCZwMH56t2Dvqofxs6BBcCFIZ\r\n" \
                           "USpxu6x6td0V7SvJCCosirSmIatj/9dSSVDQibet8q/7UK4v4ZUN80atnZz1yg==\r\n" \
                                             "-----END CERTIFICATE-----\r\n"
#endif /* FIRESTORE_FIREBASE_CA_CERT_PEM */

#endif /* __CONFIG_H__ */