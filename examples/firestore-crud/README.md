## How to use this example:

1. Clone the firestore component repo into your computer
``` bash
$ git clone https://github.com/kaizoku-oh/firestore.git
```

2. Open the firestore-crud example directory with vscode
``` bash
$ code firestore/examples/firestore-crud
```

3. Update the WiFi SSID and password in the **build_flags** section in **platformio.ini** file with your real SSID and password
``` INI
'-DWIFI_SSID="MY_WIFI_SSID"'
'-DWIFI_PASS="MY_SUPER_SECRET_PASSWORD"'
```

4. Update the firebase project ID and API key in the **firestore_config.h** file
``` C
#define FIRESTORE_FIREBASE_PROJECT_ID "MY_FIREBASE_PROJECT_ID"
#define FIRESTORE_FIREBASE_API_KEY "MY_FIREBASE_API_KEY"
```

5. Now you should be ready to go: Build, upload and monitor

6. Open your [firebase console](https://console.firebase.google.com/) and go to the firestore section, you'll find that there is a new collection and a document created.

![Firestore screenshot](https://raw.githubusercontent.com/kaizoku-oh/firestore/example-update/docs/images/firestore.png)

*Finally try to play around with the code and experiment all the CRUD functionalities.*