{
  "targets": [
    {
      "target_name": "epd",
            "sources": [
              "lib/epd.c",
              "lib/epd_driver.c",
              "lib/Config/DEV_Config.c",
              "lib/EPD_1in54_V2.c"
            ],
            "include_dirs": [
              "lib",
              "lib/Config"
            ],
            "defines": ["RPI", "USE_BCM2835_LIB"],
            "libraries": ["-lbcm2835"],
            "cflags": ["-std=c99", "-DRPI", "-DUSE_BCM2835_LIB"]
          }
  ]
}
