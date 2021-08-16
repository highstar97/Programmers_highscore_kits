#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    set<int> winner[n+1];
    set<int> loser[n+1];

    // �⺻ ���� ��� ����
    for(int i=0; i<results.size(); i++){
        winner[results[i][0]].emplace(results[i][1]);
        loser[results[i][1]].emplace(results[i][0]);
    }

    // �̱����� ������� �̱������� ��� �̱�ɷ� update
    // �� ����� �̱����� �̱������� ��� ���ɷ� update
    // 2�� ������ ���� : �� �� �������� ������Ʈ�� �ȵǴ� ��찡 �߻���
    for (int k = 0; k < 2; k++){
        for (int i = 1; i <= n; i++){
            for (auto data : winner[i]){
                for (set<int>::iterator j = winner[data].begin(); j != winner[data].end(); j++){
                    winner[i].emplace(*j);
                }
            }
            for (auto data : loser[i]){
                for (set<int>::iterator j = loser[data].begin(); j != loser[data].end(); j++){
                    loser[i].emplace(*j);
                }
            }
        }
    }

    // �̱�� ���� ��� ������ ��� = ������ ������ ���
    for(int i=1; i<=n; i++){
        if(winner[i].size()+loser[i].size() == n-1)
            answer++;
    }

    return answer;
}

int main(){
    //int n = 5;
    //vector<vector<int>> results = {{4,2},{4,3},{1,2},{2,5},{3,2}};
    //cout << solution(n,results);
    cout << solution(5,{{1,4},{4,2},{2,5},{5,3}});
}