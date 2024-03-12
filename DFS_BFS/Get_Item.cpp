#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    ** 모든 좌표를 2배 늘려서 사용 **
        왜? : 1배로 풀면 예제 1에서 (5,5) -> (5,6)으로 바로 넘어가 버리는 불상사가 발생
    전체 맵 set false
    직사각형 좌표 set true
    직사각형 내부 좌표 set false
    BFS 실행
*/
const int MAX = 102;

bool IsVisited[MAX][MAX];
int Map[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void SetMapTrueAboutRectangle(vector<vector<int>> &rectangle)
{
    for (int i = 0; i < rectangle.size(); ++i)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;

        for (int row = x1; row <= x2; ++row)
        {
            for (int col = y1; col <= y2; ++col)
            {
                Map[row][col] = 1;
            }
        }
    }
}

void SetMapFalseAboutInnerRectangle(vector<vector<int>> &rectangle)
{
    for (int i = 0; i < rectangle.size(); ++i)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;

        for (int row = x1 + 1; row < x2; ++row)
        {
            for (int col = y1 + 1; col < y2; ++col)
            {
                Map[row][col] = 0;
            }
        }
    }
}

void BFS(int characterX, int characterY, int itemX, int itemY)
{
    queue<pair<int, int>> Queue;
    Queue.emplace(make_pair(characterX, characterY));
    IsVisited[characterX][characterY] = true;

    while (!Queue.empty())
    {
        int CurrentX = Queue.front().first;
        int CurrentY = Queue.front().second;
        Queue.pop();

        if (CurrentX == itemX && CurrentY == itemY)
        {
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurrentX + dx[i];
            int NextY = CurrentY + dy[i];

            if (NextX < 0 || NextX > MAX || NextY < 0 || NextY > MAX)
            {
                continue;
            }

            if (IsVisited[NextX][NextY] == false && Map[NextX][NextY] > 0)
            {
                Queue.emplace(make_pair(NextX, NextY));
                IsVisited[NextX][NextY] = true;
                Map[NextX][NextY] = Map[CurrentX][CurrentY] + 1;
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    SetMapTrueAboutRectangle(rectangle);
    SetMapFalseAboutInnerRectangle(rectangle);
    BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    return Map[itemX * 2][itemY * 2] / 2;
}

int main()
{
    vector<vector<int>> rectangle = {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
    int characterX = 1, characterY = 3, itemX = 7, itemY = 8;
    cout << solution(rectangle, characterX, characterY, itemX, itemY);
}