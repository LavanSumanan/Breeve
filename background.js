var countdown = document.getElementById("countdown");

function count () {
    for (let i = 10; i > 0; i--) {
        setTimeout(countdown.innerHTML = ""+i, 1000);
    }
}

countdown.onload = function() {
    setTimeout(count(), 3000);
}

chrome.browserAction.onClicked.addListener(function (activeTab) {
    chrome.tabs.create({ 'url': chrome.extension.getURL('calm.html') }, function (tab) {
    });
});