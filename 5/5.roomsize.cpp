#include<iostream>
#include<algorithm>

using namespace std;

const int nMAX = 100;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
char nRoom;

bool desc(int a, int b);
void cInput(char Map[][nMAX], int n, int m);
void DFS(int x, int y, char Map[][nMAX],int &nCnt,int visit[][nMAX]);

int main(void) {
		int arr[100] = { 0 };
		int visit[nMAX][nMAX] = { 0 };
		char Map[nMAX][nMAX] = { 0 };
		int nCnt=0, k=0;
		int nRoom_cnt=1;
		nRoom = '1';
		cin >> n >> m;
		cInput(Map, n, m);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Map[i][j] == '.')
				{
					DFS(i, j, Map,nCnt,visit);
					nRoom++;
					arr[nRoom_cnt++] = nCnt;
					nCnt = 0;
				}
			}
		}
		sort(arr, arr + nRoom_cnt,desc);

		cout << nRoom_cnt-1 << '\n';
		for (int i = 0; i < nRoom_cnt-1; i++) cout << arr[i] << " ";
		cout << '\n';
	

	return 0;
}

bool desc(int a, int b) { return a > b; }

void cInput(char Map[][nMAX], int n, int m)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> Map[i][j];
}

void DFS(int x, int y, char Map[][nMAX],int &nCnt,int visit[][nMAX])
{
	int nx, ny;

	visit[x][y] = 1;
	Map[x][y] = nRoom;
	nCnt++;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;

		if (visit[nx][ny] == 0 && Map[nx][ny] == '.') {
			DFS(nx, ny, Map,nCnt,visit);
		}
	}
}
