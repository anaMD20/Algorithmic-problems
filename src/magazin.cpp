#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

void dfs(const std::vector<std::vector<int>>& gf,
    std::unordered_map<int, std::vector<int>>& results, int node) {
    std::vector<bool> visited(gf.size(), false);
    std::vector<int> result;
    result.reserve(gf.size());
    std::vector<int> stack;
    stack.push_back(node);

    while (!stack.empty()) {
        int currN = stack.back();
        stack.pop_back();

        if (!visited[currN]) {
            visited[currN] = true;

            for (auto it = gf[currN].rbegin(); it != gf[currN].rend(); ++it) {
                int nextNode = *it;
                if (!visited[nextNode]) {
                    stack.push_back(nextNode);
                }
            }

            if (currN != node)
                result.push_back(currN);
        }
    }

    results[node] = result;
}

int main() {
    std::ifstream fin("magazin.in");
    std::ofstream fout("magazin.out");

    int N, Q;
    fin >> N >> Q;

    std::vector<std::vector<int>> gf(N + 1, std::vector<int>());
    std::vector<int*> parents(N + 1);

    for (int i = 2; i <= N; ++i) {
        int parent;
        fin >> parent;
        gf[parent].push_back(i);
        parents[i] = &gf[parent].back();
    }

    std::unordered_map<int, std::vector<int>> nodeOrders;

    for (int i = 1; i <= N; ++i) {
        dfs(gf, nodeOrders, i);
    }

    std::vector<int> results(Q);

    for (int i = 0; i < Q; ++i) {
        int D, E;
        fin >> D >> E;

        int result = -1;
        if (E <= static_cast<int>(nodeOrders[D].size())) {
            result = nodeOrders[D][E - 1];
        }

        results[i] = result;
    }

    for (int i = 0; i < Q; ++i) {
        fout << results[i] << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
