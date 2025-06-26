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
git clone https://github.com/Kazio73/epd1in54v2-node.git
cd epd1in54v2-node
npm install
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

## Acknowledgments
- This project is developed using the **non-commercial license** of [JetBrains WebStorm](https://www.jetbrains.com/webstorm/). Thanks to JetBrains for supporting open source!
- Special thanks to [ChatGPT](https://chat.openai.com) for development assistance, debugging support, and tireless collaboration. 🤖❤️

## License
MIT