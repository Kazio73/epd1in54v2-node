const { createCanvas } = require('canvas');
const epd = require('../index');

(async () => {
    await epd.init();

    const canvas = createCanvas(200, 200);
    const ctx = canvas.getContext('2d');
    ctx.fillStyle = 'white';
    ctx.fillRect(0, 0, 200, 200);
    ctx.fillStyle = 'black';
    ctx.font = 'bold 22px monospace';
    const now = new Date().toLocaleTimeString('pl-PL');
    ctx.fillText(now, 30, 100);

    const imageData = ctx.getImageData(0, 0, 200, 200).data;
    const buffer = Buffer.alloc((200 * 200) / 8, 0xff);
    for (let i = 0; i < 200 * 200; i++) {
        const j = i * 4;
        const bit = imageData[j] < 128 ? 0 : 1;
        const byteIndex = Math.floor(i / 8);
        const bitIndex = 7 - (i % 8);
        if (bit === 0) buffer[byteIndex] &= ~(1 << bitIndex);
    }

    await epd.display(buffer);
    await epd.displayBase(buffer);
    await epd.sleep();
})();