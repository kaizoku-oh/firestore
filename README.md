<p align="center">
  <!-- <img src="https://raw.githubusercontent.com/kaizoku-oh/firestore/config/docs/images/firebase.gif" width=50% height=50%> -->
  <img src="https://raw.githubusercontent.com/kaizoku-oh/firestore/0fc5940cf3f8b280a7cfea44766415506bfb3697/docs/images/firebase-logo.svg" width=20% height=20%>
  <h1 align="center">ESP-IDF Component for Cloud Firestore</h1>
</p>

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
5. To avoid exposing sensitive data in the code we'll store them in environment variables that'll be when building the project.

Add your WiFi SSID, WiFi password, Firebase project ID, Firebase API key as environment variables like the following:
### Window (Powershell)
``` powershell
# Set local environment variables
> $env:WIFI_SSID = '"TYPE_YOUR_WIFI_SSID_HERE"'
> $env:WIFI_PASS = '"TYPE_YOUR_WIFI_PASSWORD_HERE"'
> $env:FIRESTORE_FIREBASE_PROJECT_ID = '"TYPE_YOUR_FIREBASE_PROJECT_ID_HERE"'
> $env:FIRESTORE_FIREBASE_API_KEY = '"TYPE_YOUR_FIREBASE_API_KEY_HERE"'

# OPTIONAL: To read and verify the values of the variables that you just set:
> Get-ChildItem Env:WIFI_SSID
> Get-ChildItem Env:WIFI_PASS
> Get-ChildItem Env:FIRESTORE_FIREBASE_PROJECT_ID
> Get-ChildItem Env:FIRESTORE_FIREBASE_API_KEY
```

### Linux (Bash)
``` bash
# Set local environment variables
$ export WIFI_SSID='"TYPE_YOUR_WIFI_SSID_HERE"'
$ export WIFI_PASS='"TYPE_YOUR_WIFI_PASS_HERE"'
$ export FIRESTORE_FIREBASE_PROJECT_ID='"TYPE_YOUR_FIREBASE_PROJECT_ID_HERE"'
$ export FIRESTORE_FIREBASE_API_KEY='"TYPE_YOUR_FIREBASE_PROJECT_ID_HERE"'

# OPTIONAL: To read and verify the values of the variables that you just set:
$ echo $WIFI_SSID
$ echo $WIFI_PASS
$ echo $FIRESTORE_FIREBASE_PROJECT_ID
$ echo $FIRESTORE_FIREBASE_API_KEY
```

## Don't know where to get your Project ID and API key? Easy:
* Open you [firebase console](https://console.firebase.google.com)
* Go to Project settings 
* Scroll down to **SDK setup and configuration**
* Select the **Config** option and you'll be presented with something like this:

From there you can copy your **projectId** and **apiKey**.
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
6. Finally you can **build** project, **upload** the firmware to the board and start a serial **monitor** all with a single combined command:
``` bash
$ pio run --target upload --target monitor
```

## TODO

* Add contribution guide
* Refactor code and remove repeated parts
* Add doxygen comments
* Add anonymous authentication
* Add CI/CD
* Add thread safety

## Authors

* **Bayrem Gharsellaoui** - *Initial work* - [kaizoku-oh](https://github.com/kaizoku-oh)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Resources

* [Use the Cloud Firestore REST API](https://firebase.google.com/docs/firestore/use-rest-api)
