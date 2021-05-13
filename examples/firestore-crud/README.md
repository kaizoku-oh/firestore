## Getting Started with the example

#### 1. Clone firestore repo
``` bash
$ git clone https://github.com/kaizoku-oh/firestore.git
```

#### 2. Clone the firestore component for the example
``` bash
$ cd examples/firestore-crud
$ git submodule update --init
```

#### 3. Set your configuration in environment variables:

For more information see [How to use this component with PlatformIO](https://github.com/kaizoku-oh/firestore#how-to-use-this-component-with-platformio).

#### 4. Build, upload and monitor
``` bash
$ pio run --target upload --target monitor
```
