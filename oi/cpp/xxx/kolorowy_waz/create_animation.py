import hashlib

import cv2
import numpy as np


def hex_to_bgr(hex_color):
    rgb = tuple(int(hex_color[i : i + 2], 16) for i in (4, 2, 0))
    return rgb


def set_colors(image):
    for i in range(len(image)):
        for j in range(len(image[i])):
            if image[i][j] > 0:
                image[i][j] = hex_to_bgr(
                    hashlib.md5(bytes(image[i][j])).hexdigest()[:6]
                )
            else:
                image[i][j] = [0, 0, 0]


def process_data(m, multiplier, fps):
    fourcc = cv2.VideoWriter_fourcc(*"XVID")
    result = cv2.VideoWriter("snake.mp4", fourcc, fps, (m * multiplier, m * multiplier))
    data = open("data.out", "r").read()[:-1].split("\n\n")

    for im in data:
        im = [list(map(int, line.split())) for line in im.split("\n")]
        set_colors(im)
        im = np.array(im, dtype=np.uint8)
        im = cv2.resize(
            im, (m * multiplier, m * multiplier), interpolation=cv2.INTER_AREA
        )
        result.write(im)

    result.release()


if __name__ == "__main__":
    process_data(300, 6, 60)
