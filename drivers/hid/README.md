### Userspace Daemon

```
gcc -g control-daemon.c -O3 -o control-daemon
```

### Devicetree Drivers

```
dtc -O dtb -o pipboy-control.dtbo ./hid/pipboy-control.dts
sudo cp pipboy-control.dtbo /boot/firmware/overlays/
```

### Enable Driver

Add the following to `/boot/firmware/config.txt` and reboot. On reboot the INFO LED should be flashing if the driver loaded.

```
dtoverlay=pipboy-control
```

### Known Errors

+ Apparently the MCP23017 kernel module does not support enabling the internal pullups https://www.elektranox.org/2017/01/0002-mcp23017/

Once the driver is loaded the chip registers can be read via `cat /sys/kernel/debug/regmap/13-0020/registers`
