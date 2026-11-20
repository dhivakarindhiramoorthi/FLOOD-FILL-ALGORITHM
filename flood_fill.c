#include <stdio.h>

#define MAX 50

int image[MAX][MAX];
int rows, cols;

/* 4-connected recursive flood fill */
void floodFill(int x, int y, int oldColor, int newColor)
{
    /* Check image boundaries */
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;

    /* Replace only pixels having the original color */
    if (image[x][y] != oldColor)
        return;

    image[x][y] = newColor;

    /* Visit the four neighbouring pixels */
    floodFill(x - 1, y, oldColor, newColor); /* Up */
    floodFill(x + 1, y, oldColor, newColor); /* Down */
    floodFill(x, y - 1, oldColor, newColor); /* Left */
    floodFill(x, y + 1, oldColor, newColor); /* Right */
}

int main(void)
{
    int i, j, startX, startY;
    int oldColor, newColor;

    printf("Enter number of rows and columns (maximum %d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows <= 0 || rows > MAX || cols <= 0 || cols > MAX)
    {
        printf("Invalid image dimensions.\n");
        return 1;
    }

    printf("Enter the image pixels (integer colors):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (scanf("%d", &image[i][j]) != 1)
            {
                printf("Invalid pixel value.\n");
                return 1;
            }
        }
    }

    printf("Enter starting pixel row and column (0-based): ");
    if (scanf("%d %d", &startX, &startY) != 2 ||
        startX < 0 || startX >= rows || startY < 0 || startY >= cols)
    {
        printf("Invalid starting position.\n");
        return 1;
    }

    printf("Enter new color: ");
    if (scanf("%d", &newColor) != 1)
    {
        printf("Invalid color.\n");
        return 1;
    }

    oldColor = image[startX][startY];

    if (oldColor != newColor)
        floodFill(startX, startY, oldColor, newColor);

    printf("\nImage after flood fill:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }

    return 0;
}
