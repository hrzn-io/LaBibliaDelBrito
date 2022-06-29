#include <iostream>

using namespace std;

class Map
{
private:
	int matrix[100][100];
	int n, v;

public:
	Map();
    ~Map();
	void init();
	void move();
	void print();	
};

Map::Map()
{
	n = v = 0;
    do {
        cout << "set map size (between 0 and 99) :" << endl;
	    cin >> n;
    } while(n < 0 || n > 99);
	cout << "set the value :" << endl;
	cin >> v;

}

void Map::move()
{
    int lock = 0;
    int tmp_lock = lock;
    for(int x = 0 ; x < n ; x++) {
        if(tmp_lock == lock) {
            int y = 0;
            matrix[y][x] = v;
            print();
            for(y = 0 ; y < n - 1 ; y++) {
                matrix[y + 1][x] = v;
                matrix[y][x] = 0;
                print();
            }
            matrix[y][x] = 0;
            tmp_lock = !tmp_lock;
        } else {
            int y = n - 1;
            matrix[y][x] = v;
            print();
            for(y = n - 1 ; y > 0 ; y--) {
                matrix[y - 1][x] = v;
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
		cout << "\n";
	}
	cout << "\n";
}

Map::~Map()
{
	v = 0;
}

int main()
{
	Map map;
	map.move();
	return 0;
}
