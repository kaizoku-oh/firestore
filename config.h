#ifndef __CONFIG_H__
#define __CONFIG_H__

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
#define FIRESTORE_FIREBASE_CA_CERT_PEM                                                             \
                                              "-----BEGIN CERTIFICATE-----\r\n"                    \
                            "MIIFljCCA36gAwIBAgINAgO8U1lrNMcY9QFQZjANBgkqhkiG9w0BAQsFADBHMQsw\r\n" \
                            "CQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEU\r\n" \
                            "MBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMjAwODEzMDAwMDQyWhcNMjcwOTMwMDAw\r\n" \
                            "MDQyWjBGMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZp\r\n" \
                            "Y2VzIExMQzETMBEGA1UEAxMKR1RTIENBIDFDMzCCASIwDQYJKoZIhvcNAQEBBQAD\r\n" \
                            "ggEPADCCAQoCggEBAPWI3+dijB43+DdCkH9sh9D7ZYIl/ejLa6T/belaI+KZ9hzp\r\n" \
                            "kgOZE3wJCor6QtZeViSqejOEH9Hpabu5dOxXTGZok3c3VVP+ORBNtzS7XyV3NzsX\r\n" \
                            "lOo85Z3VvMO0Q+sup0fvsEQRY9i0QYXdQTBIkxu/t/bgRQIh4JZCF8/ZK2VWNAcm\r\n" \
                            "BA2o/X3KLu/qSHw3TT8An4Pf73WELnlXXPxXbhqW//yMmqaZviXZf5YsBvcRKgKA\r\n" \
                            "gOtjGDxQSYflispfGStZloEAoPtR28p3CwvJlk/vcEnHXG0g/Zm0tOLKLnf9LdwL\r\n" \
                            "tmsTDIwZKxeWmLnwi/agJ7u2441Rj72ux5uxiZ0CAwEAAaOCAYAwggF8MA4GA1Ud\r\n" \
                            "DwEB/wQEAwIBhjAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwEgYDVR0T\r\n" \
                            "AQH/BAgwBgEB/wIBADAdBgNVHQ4EFgQUinR/r4XN7pXNPZzQ4kYU83E1HScwHwYD\r\n" \
                            "VR0jBBgwFoAU5K8rJnEaK0gnhS9SZizv8IkTcT4waAYIKwYBBQUHAQEEXDBaMCYG\r\n" \
                            "CCsGAQUFBzABhhpodHRwOi8vb2NzcC5wa2kuZ29vZy9ndHNyMTAwBggrBgEFBQcw\r\n" \
                            "AoYkaHR0cDovL3BraS5nb29nL3JlcG8vY2VydHMvZ3RzcjEuZGVyMDQGA1UdHwQt\r\n" \
                            "MCswKaAnoCWGI2h0dHA6Ly9jcmwucGtpLmdvb2cvZ3RzcjEvZ3RzcjEuY3JsMFcG\r\n" \
                            "A1UdIARQME4wOAYKKwYBBAHWeQIFAzAqMCgGCCsGAQUFBwIBFhxodHRwczovL3Br\r\n" \
                            "aS5nb29nL3JlcG9zaXRvcnkvMAgGBmeBDAECATAIBgZngQwBAgIwDQYJKoZIhvcN\r\n" \
                            "AQELBQADggIBAIl9rCBcDDy+mqhXlRu0rvqrpXJxtDaV/d9AEQNMwkYUuxQkq/BQ\r\n" \
                            "cSLbrcRuf8/xam/IgxvYzolfh2yHuKkMo5uhYpSTld9brmYZCwKWnvy15xBpPnrL\r\n" \
                            "RklfRuFBsdeYTWU0AIAaP0+fbH9JAIFTQaSSIYKCGvGjRFsqUBITTcFTNvNCCK9U\r\n" \
                            "+o53UxtkOCcXCb1YyRt8OS1b887U7ZfbFAO/CVMkH8IMBHmYJvJh8VNS/UKMG2Yr\r\n" \
                            "PxWhu//2m+OBmgEGcYk1KCTd4b3rGS3hSMs9WYNRtHTGnXzGsYZbr8w0xNPM1IER\r\n" \
                            "lQCh9BIiAfq0g3GvjLeMcySsN1PCAJA/Ef5c7TaUEDu9Ka7ixzpiO2xj2YC/WXGs\r\n" \
                            "Yye5TBeg2vZzFb8q3o/zpWwygTMD0IZRcZk0upONXbVRWPeyk+gB9lm+cZv9TSjO\r\n" \
                            "z23HFtz30dZGm6fKa+l3D/2gthsjgx0QGtkJAITgRNOidSOzNIb2ILCkXhAd4FJG\r\n" \
                            "AJ2xDx8hcFH1mt0G/FX0Kw4zd8NLQsLxdxP8c4CU6x+7Nz/OAipmsHMdMqUybDKw\r\n" \
                            "juDEI/9bfU1lcKwrmz3O2+BtjjKAvpafkmO8l7tdufThcV4q5O8DIrGKZTqPwJNl\r\n" \
                            "1IXNDw9bg1kWRxYtnCQ6yICmJhSFm/Y3m6xv+cXDBlHz4n/FsRC6UfTd\r\n"         \
                                                "-----END CERTIFICATE-----\r\n"

#endif /* FIRESTORE_FIREBASE_CA_CERT_PEM */

#endif /* __CONFIG_H__ */