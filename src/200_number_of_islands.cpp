200. Number of Islands 岛屿数量
//作者: yuelilily
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

using namespace std;

#include <vector>
#include <iostream>

class UnionFind {
private:
	vector<int> parent;		//每个岛屿树根
	vector<int> rank;		//每个岛屿树高
	int count;

public:
	UnionFind(vector<vector<char>>& grid) {
		count = 0;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					parent.push_back(i * n + j);
					++count;
				}
				else {
					parent.push_back(-1);
				}
				rank.push_back(0);
			}
		}
	}

	int find(int i) {		//递归寻找树根
		if (parent[i] != i) {
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	void unite(int x, int y) {
		int rootx = find(x);  //寻找列根
		int rooty = find(y);  //寻找行根
		if (rootx != rooty) {
			if (rank[rootx] < rank[rooty]) {		//树高小的贴到树高大的上（path compression optimization).
				swap(rootx, rooty);
			}
			parent[rooty] = rootx;					//小树的父母指向树高的
			if (rank[rootx] == rank[rooty]) rank[rootx] += 1; //树高加一
			--count;
		}
	}

	int getCount() const {
		return count;
	}
};

int numIslands(vector<vector<char>>& grid) {
	int nr = grid.size();
	if (!nr) return 0;
	int nc = grid[0].size();

	//并查集初始化，岛屿点用行列信息特殊化每一个点，非岛屿点设为-1.
	UnionFind uf(grid);
	for (int r = 0; r < nr; ++r) {
		for (int c = 0; c < nc; ++c) {
			if (grid[r][c] == '1') {
				//确定和岛屿点连接后，检查周围4-neighborhood，是岛屿的就用并查集unite.
				if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * nc + c, (r - 1) * nc + c);
				if (r + 1 < nr && grid[r + 1][c] == '1') uf.unite(r * nc + c, (r + 1) * nc + c);
				if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
				if (c + 1 < nc && grid[r][c + 1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
			}
		}
	}

	return uf.getCount();
}

int main(int argc, char* argv[])
{
	vector<vector<char>> grid(
		4,
		vector<char>(
			5, '0'
	));

	grid[0][0] = '1';
	grid[0][1] = '1';
	grid[1][0] = '1';
	grid[1][1] = '1';
	grid[1][0] = '1';
	grid[2][2] = '1';
	grid[3][3] = '1';
	grid[3][4] = '1';

	int num_islands = numIslands(grid);

	cout << num_islands << endl;

	return 0;
}

//输入：grid = [
//		["1", "1", "0", "0", "0"],
//		["1", "1", "0", "0", "0"],
//		["0", "0", "1", "0", "0"],
//		["0", "0", "0", "1", "1"]
//]
//输出：3

