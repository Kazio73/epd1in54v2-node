{
  "targets": [
    {
      "target_name": "epd",
      "sources": [
        "src/epd.c",
        "src/epd_driver.c",
        "src/lib/Config/DEV_Config.c",
        "src/lib/EPD_1in54_V2.c"
      ],
      "include_dirs": [
        "src/lib",
        "src/lib/Config"
      ],
      "defines": ["RPI", "USE_BCM2835_LIB"],
      "libraries": ["-lbcm2835"],
      "cflags": ["-std=c99", "-DRPI", "-DUSE_BCM2835_LIB"]
    }
  ]
}