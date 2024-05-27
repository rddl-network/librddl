# librddl
A library containing support for RDDL network designed to be integrated into embedded devices.

# Prerequisites
Need following libraries

  ```
  sudo apt-get update
  sudo apt-get install protobuf-compiler libprotobuf-c-dev
  ```

# Virtual python environment
Create a virtual python environment to create run the automated protobuf file generation

  ```
  virtualenv  -p /usr/bin/python3.11 v311
  ```

  Source the environment
  ```
  source v311/bin/activate
  ```

# Generate the protobuf files the language of choice
Currently two languages are supported python and C. Run
  ```
  python generate_proto.py --python 
  ```
  to generate the python bindings or 
  ```
  python generate_proto.py 
  ```
  to generate the C bindings.

