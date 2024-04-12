const gameBoard = document.getElementById('game-board');
let snake = [{ top: 50, left: 50 }];
let direction = { x: 0, y: 0 };
let apple = null;

function createApple() {
    const top = Math.floor(Math.random() * 19) * 20;
    const left = Math.floor(Math.random() * 19) * 20;
    apple = { top, left };
    const appleElement = document.createElement('div');
    appleElement.className = 'apple';
    appleElement.style.top = `${top}px`;
    appleElement.style.left = `${left}px`;
    gameBoard.appendChild(appleElement);
}

function createSnakeSegment(top, left) {
    const segment = document.createElement('div');
    segment.className = 'snake-segment';
    segment.style.top = `${top}px`;
    segment.style.left = `${left}px`;
    return segment;
}

function moveSnake() {
    const head = Object.assign({}, snake[0]); // Copy the head
    head.top += direction.y * 20;
    head.left += direction.x * 20;

    snake.unshift(head); // Add new head to snake

    if (apple && apple.top === head.top && apple.left === head.left) {
        // Eat apple
        gameBoard.removeChild(document.querySelector('.apple'));
        createApple();
    } else {
        // Remove tail
        gameBoard.removeChild(snake.pop().element);
    }

    const headElement = createSnakeSegment(head.top, head.left);
    headElement.className += ' snake-head';
    snake[0].element = headElement;
    gameBoard.appendChild(headElement);
}

function changeDirection(event) {
    const key = event.key;
    if (key === 'ArrowUp' && direction.y === 0) direction = { x: 0, y: -1 };
    if (key === 'ArrowDown' && direction.y === 0) direction = { x: 0, y: 1 };
    if (key === 'ArrowLeft' && direction.x === 0) direction = { x: -1, y: 0 };
    if (key === 'ArrowRight' && direction.x === 0) direction = { x: 1, y: 0 };
}

document.addEventListener('keydown', changeDirection);
createApple();
setInterval(moveSnake, 200);
