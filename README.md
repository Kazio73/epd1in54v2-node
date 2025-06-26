# epd1in54v2-node

Native Node.js bindings for the Waveshare 1.54" V2.1 e-Paper display (BW).

## Features
- Full and partial refresh
- Rotation and mirroring support
- Fast updates via N-API and low-level C driver

## Requirements
- Raspberry Pi Zero/2/3/4
- Node.js >= 20
- libbcm2835 installed (`sudo apt install libbcm2835-dev`)
- `canvas` module (for image generation)

## Installation
```bash
git clone https://github.com/youruser/epd1in54v2-node.git
cd epd1in54v2-node
npm install

# Build steps
sudo apt update
sudo apt install build-essential libbcm2835-dev
npx node-gyp clean
npx node-gyp configure
npx node-gyp build
```
> ⚠️ Note: Running examples requires root privileges due to low-level SPI access:
```bash
sudo node examples/clock.js
```

## Example
```js
const { init, clear, display, displayPartial, displayBase, sleep } = require('./index');

(async () => {
    await init();
    await clear();
    const buffer = ...; // 200x200px, 1bpp
    await display(buffer);
    await displayBase(buffer);
    await sleep();
})();
```

## Acknowledgements
- Thanks to [JetBrains](https://www.jetbrains.com/webstorm/) for providing a non-commercial WebStorm license.
- This project is supported by ChatGPT 🤖

## License
MIT