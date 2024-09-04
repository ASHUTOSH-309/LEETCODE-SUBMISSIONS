class Solution {
public:
    int check_obstruction_y(int x, int y, int yprev,
                          vector<vector<int>>& obstacles) {
        int i = 0;
        for (auto pair : obstacles) {
            if (pair[0] == x && (pair[1] <= y || pair[1] >= yprev))
                return i;

            i++;    
        }
        return -1;
    }
    int check_obstruction_x(int x, int y, int xprev,
                          vector<vector<int>>& obstacles) {
        int i = 0;
        for (auto pair : obstacles) {
            if (pair[1] == y && (pair[0] <= x || pair[0] >= xprev))
                return i;

            i++;    
        }
        return -1;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        long long x = 0;
        long long y = 0;

        vector<string> directions = {"North", "East", "South", "West"};

        string current_direction = directions[0];
        int pointer_to_current_direction = 0;

        for (auto it : commands) {
            if (it < 0) {
                if (it == -1) {
                    if (pointer_to_current_direction == 0) {
                        pointer_to_current_direction = 3;
                        current_direction =
                            directions[pointer_to_current_direction];
                    } else {
                        pointer_to_current_direction--;
                        current_direction =
                            directions[pointer_to_current_direction];
                    }
                } else {

                    if (pointer_to_current_direction == 3) {
                        pointer_to_current_direction = 0;
                        current_direction =
                            directions[pointer_to_current_direction];
                    } else {
                        pointer_to_current_direction++;
                        current_direction =
                            directions[pointer_to_current_direction];
                    }
                }
            } else { // cases where k will range from 1 to 9
                int yprev = 0;
                int xprev = 0;

                if (current_direction == "North") {
                    yprev = y;
                    y += it;
                    if (check_obstruction_y(x, y, yprev, obstacles)) {
                        int index=check_obstruction_y(x, y, yprev, obstacles);
                        y = obstacles[x][index]-1;

                    }
                } else if (current_direction == "West") {
                    xprev = x;
                    x -= it;
                    if (check_obstruction_x(x, y, xprev, obstacles)){
                        int index=check_obstruction_x(x, y, yprev, obstacles);
                        x = obstacles[index][y]+1;
                    }
                } else if (current_direction == "East") {
                    xprev = x;
                    x += it;
                    if (check_obstruction_x(x, y, xprev, obstacles)){
                     int index=check_obstruction_x(x, y, yprev, obstacles);
                      x= obstacles[index][y]-1;
                    }
                } else if (current_direction == "South") {
                    yprev = y;
                    y -= it;
                    if (check_obstruction_y(x, y, yprev, obstacles)){
                       int index=check_obstruction_y(x, y, yprev, obstacles);
                        y = obstacles[x][index]+1;
                    }
                }
            }
        }

        return x * x + y * y;
    }
};