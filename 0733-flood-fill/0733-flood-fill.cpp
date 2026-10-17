class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int ogColor = image[sr][sc];
        image[sr][sc] = color;
        while (!q.empty()) {
            pair<int, int> u = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i], ny = u.second + dy[i];
                if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == ogColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};