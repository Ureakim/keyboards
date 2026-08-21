# Keyboard Firmware Configs

Personal [QMK](https://qmk.fm/) firmware configurations for my mechanical keyboards.

## Repository structure

```text
.
├── keyboardType/
├── users/              # Userspaces
│   └── xxx/
├── Containerfile       # Container for building
├── Justfile
```

## Getting started

Clone the repository together with its submodules:

```sh
git clone --recurse-submodules https://github.com/Ureakim/keyboards.git
cd keyboards
```

If you already cloned the repository without submodules:

```sh
just submodules
```

## Building

The repository uses [`just`](https://github.com/casey/just) to provide a small set of reproducible build commands.

A container image is used to provide the QMK build environment, with support for either **Podman** or **Docker**. The `Justfile` automatically detects which container runtime is available.

### Prepare the build environment

```sh
just prepare
```

This initializes/updates the Git submodules and builds the local QMK container image.

### Build and enter the QMK environment

```sh
just run
```

The build environment mounts the local `kyria/` keymap and Halcyon userspace into the QMK firmware tree, so changes can be tested without copying files into a separate QMK checkout.

## Development workflow

After changing the keymap:

```sh
just run
```

Then use the QMK CLI inside the container to compile or flash the firmware as appropriate for the connected Kyria.

The repository keeps the keyboard-specific files outside the QMK source tree and mounts them into the container at build time. This keeps the personal configuration isolated from the upstream QMK repository.

## Dependencies

You will need:

* Git
* [`just`](https://github.com/casey/just)
* Docker **or** Podman
* A working USB connection to the keyboard when flashing firmware

The QMK toolchain itself is provided by the repository's container image.

## Updating dependencies

The Halcyon userspace is tracked as a Git submodule. To update it:

```sh
just submodules
```

## License

This repository contains personal configuration files and references external QMK/Halcyon projects. Refer to the upstream projects for their respective licensing terms.

## Links

* [QMK documentation](https://docs.qmk.fm/)
* [QMK Firmware](https://qmk.fm/)
* [splitkb QMK userspace](https://github.com/splitkb/qmk_userspace)
