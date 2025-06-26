const epd = require('../build/Release/epd.node');

(async () => {
    await epd.init();
    await epd.clear();

    const buffer = Buffer.alloc((200 * 200) / 8, 0xff);
    await epd.display(buffer);

    await epd.sleep();
    console.log('✅ Sanity test complete');
})();