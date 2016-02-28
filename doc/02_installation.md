# 02. Installation

BTW depends on a number 3rd-party libraries that must be properly built and
installed in order for the BTW source code to build correctly. This page
details how to install and set up these dependencies.

## LCM

LCM (Lightweight Communications and Marshalling) is a library for communication
and data encoding/decoding that is used in systems where low latency is desired
and high bandwidth usage is anticipated. LCM is better than the built-in ROS
networking components because it does not require a master/slave setup, instead
preferring to publish messages to and read messages from a set IP address.

### Instructions

 01. Ensure `build-essential` and `libglib2.0-dev` are installed
 02. Download the LCM v1.3.0 zip file from [the Releases page](https://github.com/lcm-proj/lcm/releases/tag/v1.3.0) on Github
 03. Extract the zip file to a convenient directory and `cd` into the directory
 04. Run the following commands in order:

```shell
./configure
make
sudo make install
sudo ldconfig
```

To verify that LCM has installed correctly, run `lcm-gen`. If the command exits
successfully (says "No action specified") then LCM has been installed correctly.

> For more information on LCM, see [the LCM website](http://lcm-proj.github.io).
