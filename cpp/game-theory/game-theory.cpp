/*
1. If nim-sum is non-zero, player starting first wins.
2. Mex: smallest non-negative number not present in a set.
3. Grundy=0 means game lost.
4. Grundy=mex of all possible next states.
5. Sprague-Grundy theorem:
If a game consists of sub games (nim with multiple piles)
Calculate grundy number of each sub game (each pile)
Take xor of all grundy numbers:
If non-zero, player starting first wins
*/
