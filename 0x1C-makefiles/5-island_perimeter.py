#!/usr/bin/python3
"""
This module contains a function that calculates the perimeter of an island.
The island is represented in a grid, where 0 represents a water zone and
1 represents a land zone. Cells are connected horizontally/vertically and
the grid is surrounded by water.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    :param grid: List of lists of integers where 1 represents land and 0 water
    :return: The perimeter of the island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                # Check up
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                # Check down
                if i == len(grid) - 1 or grid[i+1][j] == 0:
                    perimeter += 1
                # Check left
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                # Check right
                if j == len(grid[i]) - 1 or grid[i][j+1] == 0:
                    perimeter += 1
    return perimeter
