# Firestore ESP-IDF component

This project is an esp-idf component for Cloud Firestore NoSQL database as a service.

<!-- ![Firestore logo](https://github.com/kaizoku-oh/firestore/blob/main/docs/image/logo.png) -->
<!-- ![](https://github.com/<OWNER>/<REPOSITORY>/workflows/<WORKFLOW_NAME>/badge.svg) -->
[![GitHub Build workflow status](https://github.com/kaizoku-oh/firestore/workflows/Build/badge.svg)](https://github.com/kaizoku-oh/firestore/actions/workflows/main.yaml)
[![GitHub release](https://img.shields.io/github/v/release/kaizoku-oh/firestore)](https://github.com/kaizoku-oh/firestore/releases)
[![GitHub issues](https://img.shields.io/github/issues/kaizoku-oh/firestore)](https://github.com/kaizoku-oh/firestore/issues)
![GitHub top language](https://img.shields.io/github/languages/top/kaizoku-oh/firestore)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/kaizoku-oh/firestore/blob/main/LICENSE)
[![Twitter follow](https://img.shields.io/twitter/follow/kaizoku_ouh?style=social)](https://twitter.com/kaizoku_ouh)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

To use this component you need ESP-IDF installed on your machine, see espressif [getting started guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) on how to do that natively or you can simply use [PlatformIO](https://docs.platformio.org/en/latest/tutorials/espressif32/espidf_debugging_unit_testing_analysis.html).

### How to use this component with PlatformIO:

1. Install [PlatformIO Extension for vscode](https://platformio.org/install/ide?install=vscode)
2. Create a new project using ESP-IDF framework
3. Under the root of the project create a new directory called [components](https://docs.platformio.org/en/latest/frameworks/espidf.html#esp-idf-components)
4. Clone this repo under the **components** directory
``` bash
$ cd components
$ git clone https://github.com/kaizoku-oh/firestore.git
```
5. Under your project include directory create a new file called **firestore_config.h**
6. Add your Firebase project ID and API key in the **firestore_config.h** file like the following:
``` C
#define FIRESTORE_FIREBASE_PROJECT_ID "PUT_YOUR_FIREBASE_PROJECT_ID_HERE"
#define FIRESTORE_FIREBASE_API_KEY "PUT_YOUR_FIREBASE_API_KEY_HERE"
```
##### Finally you prject directory tree should look similar like the following:
```
my-project/
├── CMakeLists.txt
├── components
│   └── firestore
├── include
│   └── firestore_config.h
├── lib
├── platformio.ini
├── sdkconfig
├── src
│   ├── CMakeLists.txt
│   └── main.c
└── test
```
**Don't know where to get your API key?** Easy:
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
