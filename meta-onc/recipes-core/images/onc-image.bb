include recipes-core/images/core-image-base.bb

DESCRIPTION = "image for onc project"
LICENSE = "MIT"

COMPATIBLE_MACHINE = "^rpi$"

IMAGE_FEATURES += "ssh-server-openssh"
IMAGE_INSTALL:append = " packagegroup-rpi-test onc-app gpio-module lcd-module"

