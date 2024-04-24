# From Scratch: Over the Network Control



## Project Overview

The project is aimed at demonstrating a low-level device control system utilizing MQTT as a connection layer. It is designed to showcase seamless integration and automation of essential components.

## Yocto Development

- Developed components using Bitbake recipes for streamlined integration.
- Created a custom image to seamlessly incorporate project essentials.
- Designed a custom distro, integrating systemd as the init manager for enhanced control.
- Implemented a systemd service to automate the startup of both the application and kernel modules.

## Kernel Module Implementation

- Developed essential kernel modules, including an LCD character device driver and a GPIO character device driver.
- Utilized a custom device tree source (DTS) to facilitate module probing and initialization.

## Application Interface

- Designed an intuitive application interface leveraging sysfs for efficient module interaction.
- Implemented MQTT message reception to enable dynamic peripheral control.
