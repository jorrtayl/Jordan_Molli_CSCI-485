Author: Jordan Taylor and Molli Bishop
Date: 03 / 18 / 2022

Files created were a .c file(HelloGoodbye.c) for our code, a Kconfig file, and a make file. All of these files were placed in a folder that we also made, path being: /home/cs0/molmbish/android-kernel/common/drivers/. We added code to the already existing Kconfig and make files. These additions for the Kconfig file were added above the "endmenu" text, that being drivers/HelloWorld/Kconfig. As for the make file we added, at the very bottom of the file, obj-m += HelloWorld/ We also modified the BUILD_CONFIG file, below BUILD_GOLDFISH_DRIVERS we added:
CONFIG_MODULES=y
CONFIG_MODULES_FORCE_LOAD=y
CONFIG_MODULE_UNLOAD=y
CONFIG_MODULES_FORCE_UNLOAD=y
After this, we restored and installed the kernel modules. Unforunately, we were unable to get passed this stage due to failures in getting the emulator online.