#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n,vector<int>(m,0));

    // ������ ǥ��
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }

    // ���������� �� ���� ���
    for(int i=0; i<m; i++){
        if(map[0][i] != -1)
            map[0][i] = 1;
        else
            break;
    }

    // �Ʒ������� �� ���� ���
    for(int i=0; i<n; i++){
        if(map[i][0] != -1)
            map[i][0] = 1;
        else
            break;
    }

    // ���
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(map[i][j] != -1){
                int a = map[i-1][j] == -1 ? 0 : map[i-1][j];
                int b = map[i][j-1] == -1 ? 0 : map[i][j-1];
                map[i][j] = (a + b)%1000000007;
            }
        }
    }
    return map[n-1][m-1];
}

int main(){
    int m = 100, n =100;
    vector<vector<int>> puddles ={{2,2}};
    cout << solution(m,n,puddles);
}