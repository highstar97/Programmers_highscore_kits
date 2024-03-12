#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

int Size, Answer;
const int MAX = 51;
int drow[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dcol[4] = {0, 0, -1, 1};

bool IsVisited[MAX][MAX];

bool IsSame(int rot, vector<ii> &BoardBlock, vector<ii> TableBlock)
{
    // r번 회전
    for (int r = 0; r < rot; ++r)
    {
        int MaxRow = 0;
        for (int i = 0; i < TableBlock.size(); ++i)
        {
            MaxRow = max(MaxRow, TableBlock[i].first);
        }

        for (int i = 0; i < TableBlock.size(); ++i)
        {
            int row = TableBlock[i].first;
            int col = TableBlock[i].second;
            TableBlock[i].first = col;
            TableBlock[i].second = MaxRow - row;
        }
    }

    int count = 0;
    for (int i = 0; i < BoardBlock.size(); ++i)
    {
        for (int j = 0; j < TableBlock.size(); ++j)
        {
            if (BoardBlock[i].first == TableBlock[j].first && BoardBlock[i].second == TableBlock[j].second)
            {
                ++count;
                break;
            }
        }
    }

    if (count == BoardBlock.size())
    {
        return true;
    }
    return false;
}

vector<ii> RePointsToZero(vector<ii> BlockPoints)
{
    int MinRow = Size, MinCol = Size;
    for (int i = 0; i < BlockPoints.size(); ++i)
    {
        MinRow = min(MinRow, BlockPoints[i].first);
        MinCol = min(MinCol, BlockPoints[i].second);
    }

    for (int i = 0; i < BlockPoints.size(); ++i)
    {
        BlockPoints[i].first -= MinRow;
        BlockPoints[i].second -= MinCol;
    }
    return BlockPoints;
}

vector<ii> GetBlock(int row, int col, int value, vector<vector<int>> &map)
{
    vector<ii> BlockPoints;
    queue<ii> Queue;
    Queue.emplace(make_pair(row, col));
    IsVisited[row][col] = true;

    while (!Queue.empty())
    {
        int CurrentRow = Queue.front().first;
        int CurrentCol = Queue.front().second;
        BlockPoints.emplace_back(make_pair(CurrentRow, CurrentCol));
        Queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextRow = CurrentRow + drow[i];
            int NextCol = CurrentCol + dcol[i];

            if (NextRow < 0 || NextRow >= Size || NextCol < 0 || NextCol >= Size)
            {
                continue;
            }
            if (IsVisited[NextRow][NextCol] == true || map[NextRow][NextCol] != value)
            {
                continue;
            }

            Queue.emplace(make_pair(NextRow, NextCol));
            IsVisited[NextRow][NextCol] = true;
        }
    }
    return BlockPoints;
}

void Matching(vector<vector<ii>> &BoardBlocks, vector<vector<ii>> &TableBlocks)
{
    vector<bool> IsBoardUsed(BoardBlocks.size(), false);
    vector<bool> IsTableUsed(TableBlocks.size(), false);

    for (int i = 0; i < BoardBlocks.size(); ++i)
    {
        vector<ii> BoardBlock = BoardBlocks[i];

        for (int j = 0; j < TableBlocks.size(); ++j)
        {
            if (IsBoardUsed[i])
            {
                break;
            }

            if (IsTableUsed[j])
            {
                continue;
            }

            vector<ii> TableBlock = TableBlocks[j];
            if (BoardBlock.size() != TableBlock.size())
            {
                continue; // 두 블록의 크기가 같아야 함
            }

            for (int r = 0; r < 4; ++r)
            {
                // 두 블록의 위치 비교
                if (IsSame(r, BoardBlock, TableBlock))
                {
                    // 저장
                    Answer += BoardBlock.size();
                    IsBoardUsed[i] = true;
                    IsTableUsed[j] = true;
                    break;
                }
            }
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    Size = game_board.size();
    vector<vector<ii>> BoardBlocks;
    vector<vector<ii>> TableBlocks;
    // game_board의 빈 블록들 구하기
    for (int row = 0; row < Size; ++row)
    {
        for (int col = 0; col < Size; ++col)
        {
            if (game_board[row][col] == 0 && IsVisited[row][col] == false)
            {
                BoardBlocks.emplace_back(RePointsToZero(GetBlock(row, col, 0, game_board)));
            }
        }
    }

    // IsVisited 초기화
    for (int i = 0; i < Size; ++i)
    {
        for (int j = 0; j < Size; ++j)
        {
            IsVisited[i][j] = false;
        }
    }

    // table의 블록들 구하기
    for (int row = 0; row < Size; ++row)
    {
        for (int col = 0; col < Size; ++col)
        {
            if (table[row][col] == 1 && IsVisited[row][col] == false)
            {
                TableBlocks.emplace_back(RePointsToZero(GetBlock(row, col, 1, table)));
            }
        }
    }

    Matching(BoardBlocks, TableBlocks);

    return Answer;
}

int main()
{
    vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
    vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};
    cout << solution(game_board, table);
}