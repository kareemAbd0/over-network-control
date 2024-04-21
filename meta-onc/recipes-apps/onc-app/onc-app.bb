
SUMMARY = "over the network control"
DESCRIPTION =  "Simple low level mqtt home control application"

# The license for the recipe
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


DEPENDS += "paho-mqtt-cpp"


S = "${WORKDIR}"


SRC_URI = "file://main.cpp \
           file://CMakeLists.txt \
           file://err.h \
           file://app/app.cpp \
           file://app/app.h \
           file://connection/connection.cpp \
           file://connection/connection.h \
           file://connection/mycallback.cpp \
           file://connection/mycallback.h \
           file://hw/lcd.cpp \
           file://hw/lcd.h \
           file://hw/led.cpp \
           file://hw/led.h"









inherit cmake
