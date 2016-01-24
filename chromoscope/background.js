chrome.app.runtime.onLaunched.addListener(function() {
    chrome.app.window.create('index.html', {
        innerBounds: {
            width: 1024,
            height: 750,
            minWidth: 480,
            minHeight: 350
        },
        id: "ChromeApps-Oscilloscope"
    });
});
