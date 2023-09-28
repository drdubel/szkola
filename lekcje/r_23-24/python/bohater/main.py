from sys import stdin

import numpy as np


def main():
    n, zycie = map(int, stdin.readline().split())
    walki = np.array([list(map(int, stdin.readline().split())) + [i] for i in range(n)])
    dobre_walki = walki[walki[:, 1] - walki[:, 0] > 0]
    zle_walki = walki[walki[:, 1] - walki[:, 0] <= 0]
    print(
        "TAK\n",
        *np.concatenate(
            (
                dobre_walki[dobre_walki[:, 0].argsort()][:, 2],
                zle_walki[(-zle_walki[:, 0]).argsort()][:, 2],
            )
        )
        + 1,
        sep=" "
    )


if __name__ == "__main__":
    main()
