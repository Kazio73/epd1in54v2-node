/*
 * MIT License
 *
 * Copyright (c) 2025 Kazik Karczewski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

const { createCanvas } = require('canvas');
const epd = require('../build/Release/epd.node');

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