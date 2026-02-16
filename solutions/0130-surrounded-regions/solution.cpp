class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++) {
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][n-1]=='O') q.push({i,n-1});
        }

        for(int j=0;j<n;j++) {
            if(board[0][j]=='O') q.push({0,j});
            if(board[m-1][j]=='O') q.push({m-1,j});
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!q.empty()) {
            auto [r,c]=q.front();
            q.pop();

            if(r<0||c<0||r>=m||c>=n||board[r][c]!='O')
                continue;

            board[r][c]='T';

            for(int k=0;k<4;k++)
                q.push({r+dr[k],c+dc[k]});
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};
