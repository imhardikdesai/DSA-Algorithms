def knapsack(capacity, weights, values):
    """Return the maximum value of items that fit in the knapsack.
    capacity: the capacity of the knapsack
    weights: a list of weights of the items
    values: a list of values of the items
    """
    if not weights or capacity <= 0:
        return 0
    elif weights[0] > capacity:
        return knapsack(capacity, weights[1:], values[1:])
    else:
        lose_it = knapsack(capacity, weights[1:], values[1:])
        use_it = knapsack(capacity - weights[0], weights[1:], values[1:]) + values[0]
        return max(lose_it, use_it)

def test_knapsack():
    weights = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    values = [60, 100, 120, 140, 150, 160, 170, 180, 190, 200]
    print( knapsack(100, weights, values) )

if __name__ == "__main__":
    test_knapsack()
