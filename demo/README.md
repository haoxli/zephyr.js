# Minicar
Minicar, an intelligent car demo based on [Zephyr.js 0.4](https://github.com/01org/zephyr.js/tree/zjs-0.4),using real-time detection of infrared and photoelectric sensor signal to achieve obstacle avoidance,and controlling by BLE and Joystick based on TCP Sockets.

## Required Zephyr.js Features
- Arduino 101 Pins
- PWM
- AIO
- GIPO
- BLE
- TCP

## Demo Features
- Turn left/right
- Coast/Brake/Forward/Reverse
- Obstacle aviodance
- Bluetooth/Joystick control

## Hardwares
- Arduino 101 (one more needed for joystick)
- PM-R3 Expansion Board
- Motor(JGA25-370)
- Steering Engine(MG996)
- Photoelectric sensor
- XBOX Joystick
- Bluetooth adapter

## Layout
![Demo Layout](layout/layout.png)

## Building
1. Get Zephyr.js code
```
$ git clone https://github.com/haoxli/zephyr.js
$ cd zephyr.js
$ source zjs-env.sh
$ make update
```

2. Build and Flash
```
$ source deps/zephyr/zephyr-env.sh
$ make JS=demo/main.js
$ make dfu
```
Detailed steps and dependences refer to Zephyr.js [README](https://github.com/01org/zephyr.js/blob/master/README.md).

## Controlling with web app

Web app is designed using Web Bluetooth API, can be openned on Andriod Chrome and connect with Arduino 101 through BLE API.

1. Build `main.js` and flash it to Arduino 101, then reboot the device with the Master Reset button to start the application.

2. Setup web server for controller

3. Open controller on Android 6.0 with Chrome >= 56.

4. Click 'Connect' to connect app with Arduino 101.

## Controlling with joystick

Joystick run with a singel Arduino 101 which connect with Ubuntu using ethernet module, and can communicate with car demo board through TCP API.

1. Build `main-tcp.js` and flash it Arduino 101 (as car board), then reboot the device with the Master Reset button to start the application.
```
$ make JS=demo/main-tcp.js
$ make dfu
```

2. Wiring joystick to another Arduino 101 (as joystick board)
* Wire all G on the JoyStick to GND on Arduino 101
* Wire all V on the JoyStick to Vcc(5v) on Arduino 101
* Wire X on the JoyStick to A0 on Arduino 101
* Wire Y on the JoyStick to A1 on Arduino 101
* Wire K on the JoyStick to A2 on Arduino 101

3. Wiring ENC28J60 ethernet to joystick board
* Wire GND on the ENC28J60 to GND on Arduino 101
* Wire VCC on the ENC28J60 to Vcc(3.3v) on Arduino 101
* Wire INT on the ENC28J60 to IO4 on Arduino 101
* Wire CS on the ENC28J60 to IO10 on Arduino 101
* Wire SI on the ENC28J60 to IO11 on Arduino 101
* Wire SO on the ENC28J60 to IO12 on Arduino 101
* Wire SCK on the ENC28J60 to IO13 on Arduino 101

4. Build `tests/test-tcp-joystick.js` and flash it to joystick board, then reboot the device with the Master Reset button to start the application.
```
$ make JS=tests/test-tcp-joystick.js
$ make dfu
```

5. Plugin bluetooth adapter on PC with Ubuntu 16.04, and run `tests/tools/test-tcp-adapter.py` to set the two boards connection.
```
$ sudo -i
# python tests/tools/test-tcp-adapter.py
```
