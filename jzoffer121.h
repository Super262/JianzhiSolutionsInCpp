#include <vector>
#include <string>

using namespace std;

bool wordExisted(vector<vector<char>> &board, vector<vector<bool>> &visited, const int startY, const int startX, const string &word, const int wordIterator)
{
    if (startX < 0 || startY < 0 || startY >= board.size() || startX >= board[0].size() || wordIterator >= word.size() || board[startY][startX] != word[wordIterator] || visited[startY][startX])
    {
        return false;
    }

    visited[startY][startX] = true;
    if (wordIterator == word.size() - 1)
    {
        return true;
    }
    else
    {
        bool result = wordExisted(board, visited, startY + 1, startX, word, wordIterator + 1) ||
                      wordExisted(board, visited, startY - 1, startX, word, wordIterator + 1) ||
                      wordExisted(board, visited, startY, startX + 1, word, wordIterator + 1) ||
                      wordExisted(board, visited, startY, startX - 1, word, wordIterator + 1);
        if (result)
        {
            return true;
        }
        else
        {
            visited[startY][startX] = false;
            return false;
        }
    }
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word.size() == 0)
    {
        return false;
    }
    const int height = board.size();
    if (height == 0)
    {
        return false;
    }

    const int width = board[0].size();
    if (width == 0)
    {
        return false;
    }

    vector<vector<bool>> visited(height);
    for (int i = 0; i < height; ++i)
    {
        visited[i] = vector<bool>(width, false);
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (wordExisted(board, visited, i, j, word, 0))
            {
                return true;
            }
        }
    }

    return false;
}
