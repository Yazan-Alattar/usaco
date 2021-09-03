
typedef long long ll;
#define endl "\n"
const int M = 1007;
const ll mod = 1e9 + 7;

ll n, m, k, a[M], b[M], dp[M][M][12];

int main()
{
    ifstream cin ("team.in");
    ofstream cout ("team.out");
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j][0] = 1;
    for(int c = 1; c <= k; ++c){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j][c] = (dp[i - 1][j][c] + dp[i][j - 1][c] - dp[i - 1][j - 1][c] + mod) % mod;
                if(a[i] > b[j]) dp[i][j][c] = (dp[i][j][c] + dp[i - 1][j - 1][c - 1]) % mod;
            }
        }
    }
    cout << dp[n][m][k] << endl;
    return 0;
}
// Don't forget special cases. (n = 1?)
// Look for the constraints. (Runtime array? overflow?)
