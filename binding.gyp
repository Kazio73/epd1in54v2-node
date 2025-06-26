{
  "targets": [
    {
      "target_name": "epd",
      "sources": [
        "src/epd.c",
        "src/epd_driver.c",
        "src/DEV_Config.c"
      ],
      "include_dirs": ["<!(node -e \"require('node-addon-api').include\")"],
      "dependencies": ["<!(node -e \"require('node-addon-api').gyp\")"],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
      "libraries": ["-lbcm2835"]
    }
  ]
}
