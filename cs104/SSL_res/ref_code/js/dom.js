function makeChanges() {
    let things = document.getElementsByTagName("img");
    for (let i = 0; i < things.length; i++) {
        things[i].setAttribute("src", "timepass.png");
    }

    let thingss = document.getElementsByTagName("h1");
    for (let i = 0; i < thingss.length; i++) {
        thingss[i].remove();
    }
    let thingsss = document.getElementsByTagName("p");
    for (let i = 0; i < thingsss.length; i++) {
        thingsss[i].innerHTML = "Enough of JavaScript, lets stop.";
    }
    let thingssss = document.getElementsByTagName("h2");
    for (let i = 0; i < thingssss.length; i++) {
        thingssss[i].innerHTML = thingssss[i].innerHTML.toUpperCase();
    }
    let mydiv = document.getElementById("div1");
    mydiv.innerHTML += "<h3></h3>";
}

