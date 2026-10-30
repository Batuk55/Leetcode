/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let board = Array(9).fill('');
    let winningPatterns = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6]
    ];

    // Place moves on the board
    for (let i = 0; i < moves.length; i++) {
        let [row, col] = moves[i];

        let index = row * 3 + col;

        // A plays X, B plays O
        board[index] = (i % 2 === 0) ? 'X' : 'O';

        // Check winning patterns
        for (let pattern of winningPatterns) {
            let pos0 = board[pattern[0]];
            let pos1 = board[pattern[1]];
            let pos2 = board[pattern[2]];

            if (pos0 !== '' && pos0 === pos1 && pos1 === pos2) {
                return pos0 === 'X' ? 'A' : 'B';
            }
        }
    }

    // All 9 cells filled and nobody won

    if (moves.length === 9) {
        return 'Draw';
    }
    

    return 'Pending';
};