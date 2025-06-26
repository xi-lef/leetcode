class Solution {
public:
    bool squareIsWhite(const string& coordinates) {
        const int col = coordinates[0] - 'a';
        const int row = coordinates[1] - '0';
        return row % 2 == col % 2;
        // return col % 2 == 0 ? row % 2 == 0 : row % 2 == 1;
    }
};