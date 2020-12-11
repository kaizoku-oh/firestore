# Firestore ESP-IDF component

This project is an esp-idf component for Cloud Firestore NoSQL database as a service.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

To use this component you need ESP-IDF installed on your machine, see espressif [getting started guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) on how to do that natively or you can simply use [PlatformIO](https://docs.platformio.org/en/latest/tutorials/espressif32/espidf_debugging_unit_testing_analysis.html).

### Configuring the examples

#### pio-esp-idf
This is an example made with PlatformIO that includes the firestore component by using EXTRA_COMPONENT_DIRS option in the root CMakeLists.txt file. This option represents a list of extra directories to search for components in the project.

The example contains 2 config files that we need to change in order for it to work correctly.

First wifi_config.h, this file need to contain your  wifi ssid and password:

``` C
#define WIFI_SSID "PUT_YOUR_WIFI_SSID_HERE"
#define WIFI_PASS "PUT_YOUR_WIFI_PASS_HERE"
```

The second config file is firestore_config.h which needs to contain your firestore component configuration, feel free to change these configs, but the most important ones are the following:

``` C
#define FIRESTORE_FIREBASE_PROJECT_ID "PUT_YOUR_FIREBASE_PROJECT_ID_HERE"
#define FIRESTORE_FIREBASE_API_KEY "PUT_YOUR_FIREBASE_API_KEY_HERE"
```

**Don't know where to get your API key?** easy:
* Open you firebase console
* Go to Project settings 
* Scroll down to Firebase SDK snippet
* Select the Config option and you'll be presented with something like this:

``` Javascript
const firebaseConfig = {
  apiKey: "YOUR_FIRESTORE_FIREBASE_API_KEY",
  authDomain: "XXXXXXXXXXXXXXXXXXXXXXXX",
  databaseURL: "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  projectId: "YOUR_FIRESTORE_FIREBASE_PROJECT_ID",
  storageBucket: "XXXXXXXXXXXXXXXXXXXXXXXX",
  messagingSenderId: "XXXXXXXXXXXXXX",
  appId: "XXXXXXXXXXXXXXXXXXXXXX"
};
```

## TODO

* Optimize the http code
* Add doxygene comments
* Add anonymous authentication
* Add CI/CD

## Authors

* **Bayrem Gharsellaoui** - *Initial work* - [kaizoku-oh](https://github.com/kaizoku-oh)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Resources

* [Use the Cloud Firestore REST API](https://firebase.google.com/docs/firestore/use-rest-api)
