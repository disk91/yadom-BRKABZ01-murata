# Yadom BRKABZ01 (Murata CMWX1ZZABZ-091 Breakout) demo code

## What is it ?
This repository contains a demo code to connect to LoRaWan network with a [Yadom BRKAKZ01](https://yadom.fr/kit-carte-breakout-brkabz01.html) breakout board. This board is running a [Murata CMWX1ZZABZ-091](https://www.disk91.com/2019/technology/hardware/getting-started-with-st-murata-lorawan-board/) STM32/LoRaWan module.

This demo code is based on the [Disk91 IoT SDK](https://github.com/disk91/stm32-it-sdk). To be able to compile it, you need to import the SDK code into the project as detailed in the installation step.

## What does it do ?
This demo code just run 2 parallel tasks:
* one blinking the led every seconds
* one communicating a fixed payload every 30 second over LoRaWan

Thanks to ItSdk this sample code is:
* working Low Power switching the MCU in standby mode between task execution
* integrating a log console connected to LPUART1 => on PA14
* integrating a configuration console connected to USART2 => on PA2/PA3

You can setup your own OTAA credentials using the configuration console to change the settings.
The command **?**[ENTER] will show you the public console commands.
You need to login the console to access configuration. Type **changeme**[ENTER] on the console to get logged.
Then you will be able to see all the commands with **?**[ENTER] after login. 

## Get more details
This demo code is detailed in my [blog post related to the Yadom BRKABZ01](https://www.disk91.com/?p=3603) breakout board. Follow the link to get details.

## Use the demo code
In the Release directory you have a **.hex** file with a compiled version of the firmware. You can directly upload it following the procedure over DFU detailed in the blog post.

you can take a look to the demo video:
[![Alt text](https://img.youtube.com/vi/Jn5eIoJ9oiM/0.jpg)](https://www.youtube.com/watch?v=Jn5eIoJ9oiM)


## Compile the demo code

Watch the setup video for getting started (select HD display) - this one has been made for another project but the principle stays the same.

[![Alt text](https://img.youtube.com/vi/VEWrr4t8ujo/0.jpg)](https://www.youtube.com/watch?v=VEWrr4t8ujo)

1. Clone this repository and open it with AC6 environment [See here on how to install AC6 if needed](https://www.disk91.com/2018/technology/hardware/getting-started-with-nucleo32-stm32l031/)

2. Clone the [Disk91 STM32 IoT SDK repository](https://github.com/disk91/stm32-it-sdk) in the Project root directory to add the needed sdk dependencies. This project has been tested & refied with SDK [Version 1.4.1](https://github.com/disk91/stm32-it-sdk/releases/tag/v1.4.1-FW1.11.0) 

## Rq 

Yes I know, there are some LoRaWan credentials in the config file, it's to make it working immediatly for your 1st test. 


