# Moonbase Operations Repository

This is the home of the department of moonbase operations.
This contains the source files for the various projects under this team.

## Dependencies

This repository is based on google's bazel build system.
To install bazel please follow [bazel installation manual](https://bazel.build/install).

## Projects

### Masher

Masher is an electronics project aiming to make the BIOS/EFI configuration
process unnattended, reliable, and efficient.

It is an Arduino Leonardo/Micro project that consists of:

- Arduino Leonardo/Micro [AVR32u4] Firmware
- 3D CAD files to enclose in a USB Stick
- [UNIMPLEMENTED] EDA CAD files to fabricate PCBS
- Native testing library

*Dependencies:*

Masher has additional dependencies:

- Platformio
- Python3
- AVR-GCC

With an optional dependency to:

- AVRDUDE
