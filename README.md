# Firestore ESP-IDF component

This project is an esp-idf component for Cloud Firestore NoSQL database as a service.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

To use this component you need ESP-IDF installed on your machine, see espressif [getting started guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) on how to do that natively or you can simply use [PlatformIO](https://docs.platformio.org/en/latest/tutorials/espressif32/espidf_debugging_unit_testing_analysis.html).

### Configuring the examples

Before using the example code you need to configure the firestore component in firestore_config.h which needs to contain your firestore component configuration like project id, api key... Feel free to change th configs, but the most important ones are the following:

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
* Add thread safety

## Authors

* **Bayrem Gharsellaoui** - *Initial work* - [kaizoku-oh](https://github.com/kaizoku-oh)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Resources

* [Use the Cloud Firestore REST API](https://firebase.google.com/docs/firestore/use-rest-api)
