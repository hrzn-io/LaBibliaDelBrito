#include <iostream>

using namespace std;

class Map
{
private:
    int matrix[100][100];
    int n, v;

public:
    Map();
    void move();
    void print();
};

Map::Map()
{
    n = v = 0;
    do
    {
        cout << "set map size (between 0 and 99) :" << endl;
        cin >> n;
    } while (n < 0 || n > 99);
    cout << "set the value :" << endl;
    cin >> v;
}

void Map::move()
{
    int lock = 0;
    int tmp_lock = lock;
    for (int y = n - 1; y >= 0; y--)
    {
        if (tmp_lock == lock)
        {
            int x = 0;
            matrix[y][x] = v;
            print();
            for (x = 0; x < n - 1; x++)
            {
                matrix[y][x + 1] = v;
                matrix[y][x] = 0;
                print();
            }
            matrix[y][x] = 0;
            tmp_lock = !tmp_lock;
        }
        else
        {
            int x = n - 1;
            matrix[y][x] = v;
            print();
            for (x = n - 1; x > 0; x--)
            {
                matrix[y][x - 1] = v;
                matrix[y][x] = 0;
                print();
            }
            matrix[y][x] = 0;
            tmp_lock = !tmp_lock;
        }
    }
}

void Map::print()
{
    for (int x = 0; x <= n - 1; x++)
    {
        for (int y = 0; y <= n - 1; y++)
        {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Map map;
    map.move();
    return 0;
}
