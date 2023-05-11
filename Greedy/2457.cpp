#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n;
pair<pair<int, int>, pair<int, int>> s[100005];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i].X.X >> s[i].X.Y >> s[i].Y.X >> s[i].Y.Y;
    }
    sort(s + 1, s + n + 1);
    int em, ed;
    em = 3, ed = 1;
    int ans = 0;
    int i = 0;
    int tem = 3, ted = 1;
    int flag = 0;

    while (i < n) {
        i++;
        int sm = s[i].X.X;
        int sd = s[i].X.Y;
        int km = s[i].Y.X;
        int kd = s[i].Y.Y;

        if ((sm == em && sd <= ed) || sm < em) {

            //tem, ted 업데이트 (최댓값으로)
            //12/1보다 크거나 같으면 break
            if ((km == tem && kd >= ted) || km > tem)
            {
                tem = km;
                ted = kd;
                if (tem == 12 && ted >= 1) {
                    ans++;
                    flag = 1;
                    break;
                }
            }
            continue;
        }
        else {
            // 1. 시작이 tem,ted 보다 큰 경우 (꽃이 안 핀 기간 생김)
            // 2. 시작이 tem,ted 보다 작거나 같은 경우
            // -> em, ed 업데이트 12/1 보다 크거나 같으면 break

            if ((sm == tem && sd > ted) || (sm > tem)) {
                break;
            }
            else {
                ans++;
                em = tem;
                ed = ted;
                if ((km == em && kd >= ed) || km > em)
                {
                    tem = km;
                    ted = kd;
                    if (tem == 12 && ted >= 1) {
                        ans++;
                        flag = 1;
                        break;
                    }
                }

            }

        }
    }
    //flag == 0 인 경우 불가
    if (!flag)
        cout << 0;
    else
        cout << ans;
}
//N개의 꽃
//4,6,9,11 : 30 / 1,3,5,7,8,10 : 31 / 2: 28
//5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 
//6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미
//1. 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상
//피어 있도록 한다.
//2. 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다. 

//그리디한 관점에서 생각해보면 매번 현재 시점에서 피어있는 꽃 중에서
//가장 마지막에 지는 꽃을 선택하면 된다.