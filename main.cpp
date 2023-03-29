#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Node {
public:
	char dat{};
	char left{};
	char right{};
};

using vN = vector<Node>;

void print1(const vN& tree, int i) {
	cout << tree[i].dat;

	if ('.' != tree[i].left) {
		print1(tree, tree[i].left - 'A');
	}

	if ('.' != tree[i].right) {
		print1(tree, tree[i].right - 'A');
	}
}

void print2(const vN& tree, int i) {
	if ('.' != tree[i].left) {
		print2(tree, tree[i].left - 'A');
	}

	cout << tree[i].dat;

	if ('.' != tree[i].right) {
		print2(tree, tree[i].right - 'A');
	}
}

void print3(const vN& tree, int i) {
	if ('.' != tree[i].left) {
		print3(tree, tree[i].left - 'A');
	}

	if ('.' != tree[i].right) {
		print3(tree, tree[i].right - 'A');
	}

	cout << tree[i].dat;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	auto tree = vN(n);
	while (0 < (n--)) {
		char x, y, z;
		cin >> x >> y >> z;

		auto d = Node{};
		d.dat = x;
		d.left = y;
		d.right = z;

		tree[x - 'A'] = d;
	}

	print1(tree, 0);
	cout << '\n';

	print2(tree, 0);
	cout << '\n';

	print3(tree, 0);

	return 0;
}