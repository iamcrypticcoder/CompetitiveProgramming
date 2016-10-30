#include <stdio.h>

int main()
{
    int tc, TC;
    int posMe, posLift;
    int ans;

    scanf("%d", &TC);

    for(tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &posMe, &posLift);

        if(posLift > posMe) ans =(posLift - posMe) * 4 + posMe*4 + 19;
        else ans = (posMe - posLift) * 4 + posMe*4 + 19;

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
