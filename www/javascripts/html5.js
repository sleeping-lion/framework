// Create new HTML5 elements ===================================================
// -----------------------------------------------------------------------------
// This script should load before any others. We want the new elements to be
// parsed before pretty much anything happens.
// Plus, IE does not behave otherwise. The cost of being progressive...
// -----------------------------------------------------------------------------

document.createElement("section");
document.createElement("article");
document.createElement("aside");
document.createElement("footer");
document.createElement("header");
document.createElement("hgroup");
document.createElement("figure");
document.createElement("figcaption");
document.createElement("nav");