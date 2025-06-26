const { createCanvas } = require('canvas');
const epd = require('../build/Release/epd.node');

const WIDTH = 200;
const HEIGHT = 200;

function getTimeBuffer() {
    const canvas = createCanvas(WIDTH, HEIGHT);
    const ctx = canvas.getContext('2d');

    ctx.fillStyle = 'white';
    ctx.fillRect(0, 0, WIDTH, HEIGHT);

    ctx.fillStyle = 'black';
    ctx.font = 'bold 26px monospace';

    const now = new Date().toLocaleTimeString('pl-PL');
    ctx.fillText(now, 30, 110);

    const imgData = ctx.getImageData(0, 0, WIDTH, HEIGHT).data;
    const buffer = Buffer.alloc((WIDTH * HEIGHT) / 8, 0xff);
    for (let i = 0; i < WIDTH * HEIGHT; i++) {
        const j = i * 4;
        const bit = imgData[j] < 128 ? 0 : 1;
        const byteIndex = Math.floor(i / 8);
        const bitIndex = 7 - (i % 8);
        if (bit === 0) buffer[byteIndex] &= ~(1 << bitIndex);
    }

    return buffer;
}

(async () => {
    await epd.init();

    let count = 0;
    const interval = setInterval(async () => {
        const buffer = getTimeBuffer();
        await epd.display(buffer);

        if (++count >= 300) {
            console.log('♻️ Full refresh');
            await epd.displayBase(buffer);
            count = 0;
        }
    }, 5000);
})();