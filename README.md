# Desktop Utilities

**Desktop Utilities** is a small tool to handle XDG files (*.desktop*).

It can perform the following tasks:

- Install a desktop file for an application to the standard XDG desktop.
- Modify a desktop file to alter program priority.

## Building

Building *desktop-utils* can be done using GNU Make:

```
make
```

## Install

To install *desktop-utils*, run the following target:

```
make install PREFIX=(prefix)
```

The variable `PREFIX` defaults to `/usr/local`.

## Uninstall

To uninstall *desktop-utils*, run the following target using the same prefix as specified in the install process:

```
make uninstall PREFIX=(prefix)
```
