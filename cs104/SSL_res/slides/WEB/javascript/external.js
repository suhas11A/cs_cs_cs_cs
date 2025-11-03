// External JavaScript
const paragraph = document.getElementById('dynamicParagraph');

// Modify the style of the paragraph immediately
paragraph.style.color = 'red';
paragraph.style.fontSize = '20px';
paragraph.style.fontWeight = 'bold';

// Add a new element to the page dynamically
const newElement = document.createElement('p');
newElement.textContent = 'This is a dynamically added paragraph from external JavaScript.';
document.body.appendChild(newElement);
