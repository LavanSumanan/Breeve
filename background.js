var num = 1;
var x = setInterval(function () {
    document.getElementById("countdown").innerHTML = "" + num;
    num++;
    if (num == 12) {
        clearInterval(x);
        document.getElementById("countdown").innerHTML = "Good work!";
    }
}, 4000);

chrome.browserAction.onClicked.addListener(function (activeTab) {
    chrome.tabs.create({ 'url': chrome.extension.getURL('breeve.html') }, function (tab) {
    });
});